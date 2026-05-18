#include <Arduino.h>

#include <SPI.h>

#include <lmic.h>

#include <hal/hal.h>

#include "lora/lora_handler.h"

#include "lora/payload.h"

#include "config/pins.h"

#include "config/constants.h"

#include "core/console.h"

#include "core/globals.h"

#include "sensors/wind/anemometer.h"

#include "sensors/wind/wind_vane.h"

// =================================================
// LMIC PINMAP
// =================================================

const lmic_pinmap lmic_pins = {

    .nss = LORA_NSS,

    .rxtx = LMIC_UNUSED_PIN,

    .rst = LORA_RST,

    .dio = {
        LORA_DIO0,
        LORA_DIO1,
        LORA_DIO2
    }
};

// =================================================
// EVENTS LMIC
// =================================================

void onEvent(ev_t ev) {

    Serial.print("[LMIC ");
    Serial.print(os_getTime());
    Serial.print("] ");

    switch (ev) {

        case EV_JOINING:

            consoleInfo(
                "Connexion OTAA vers TTN..."
            );

            break;

        case EV_JOINED:

            consoleOk(
                "Connexion TTN réussie"
            );

            LMIC_setLinkCheckMode(0);

            lastSendMillis = millis();

            break;

        case EV_TXSTART:

            consoleInfo(
                "Début transmission radio"
            );

            break;

        case EV_TXCOMPLETE:

            consoleOk(
                "Transmission terminée"
            );

            Serial.print(
                "TXRX Flags = "
            );

            Serial.println(
                LMIC.txrxFlags
            );

            Serial.print(
                "DataLen = "
            );

            Serial.println(
                LMIC.dataLen
            );

            break;

        default:

            Serial.print(
                "Événement LMIC : "
            );

            Serial.println((unsigned) ev);

            break;
    }
}

// =================================================
// ENVOI DONNÉES
// =================================================

void envoyerDonnees() {

    if (LMIC.opmode & OP_TXRXPEND) {

        consoleWarn(
            "Transmission déjà en cours"
        );

        return;
    }

    noInterrupts();

    uint32_t impulsions =
        impulsionsVent;

    impulsionsVent = 0;

    interrupts();

    unsigned long now = millis();

    float tempsSecondes =
        (now - lastSendMillis)
        / 1000.0;

    lastSendMillis = now;

    if (tempsSecondes <= 0) {

        tempsSecondes =
            TX_INTERVAL;
    }

    float vitesseVentKmh =
        calculerVitesseVent(
            impulsions,
            tempsSecondes
        );

    // =======================
    // ALERTES
    // =======================

    alerteVent = false;

    if (
        vitesseVentKmh >=
        ALERTE_VENT_KMH
    ) {

        alerteVent = true;

        demandeEnvoiImmediate = true;

        consoleWarn(
            "ALERTE VENT VIOLENT"
        );
    }

    // =======================
    // GIROUETTE
    // =======================

    uint8_t directionIndex =
        lireDirectionIndex();

    uint16_t directionDeg =
        lireDirectionDegres();

    // =======================
    // PAYLOAD
    // =======================

    uint16_t ventX10 =
        vitesseVentKmh * 10;

    byte payload[
        5 + WEATHER_PAYLOAD_SIZE
    ];

    // =======================
    // VENT
    // =======================

    payload[0] =
        highByte(ventX10);

    payload[1] =
        lowByte(ventX10);

    payload[2] =
        directionIndex;

    payload[3] =
        highByte(directionDeg);

    payload[4] =
        lowByte(directionDeg);

    // =======================
    // MÉTÉO
    // =======================

    buildPayload(
        payload + 5
    );

    // =======================
    // ENVOI TTN
    // =======================

    LMIC_setTxData2(
        1,
        payload,
        sizeof(payload),
        0
    );

    consoleOk(
        "Payload mis en attente de transmission"
    );
}

// =================================================
// INITIALISATION LORA
// =================================================

void initLoRa() {

    consoleSection(
        "INITIALISATION LoRaWAN"
    );

    SPI.begin(
        SPI_SCK,
        SPI_MISO,
        SPI_MOSI,
        LORA_NSS
    );

    os_init();

    LMIC_reset();

    LMIC_setClockError(
        MAX_CLOCK_ERROR * 10 / 100
    );

    lastSendMillis = millis();

    consoleInfo(
        "Démarrage procédure OTAA"
    );

    LMIC_startJoining();
}

// =================================================
// LOOP LORA
// =================================================

void loopLoRa() {

    os_runloop_once();

    static unsigned long dernierEssai = 0;

    bool envoiPeriodique =

        millis() - dernierEssai >=
        TX_INTERVAL * 1000UL;

    if (
        LMIC.devaddr != 0 &&
        (
            envoiPeriodique ||
            demandeEnvoiImmediate
        )
    ) {

        dernierEssai = millis();

        if (!(LMIC.opmode &
            OP_TXRXPEND)) {

            consoleInfo(
                "Nouvel envoi périodique"
            );

            envoyerDonnees();

            demandeEnvoiImmediate =
                false;
        }
    }
}