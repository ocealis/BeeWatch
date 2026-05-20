#include <Arduino.h>

#include <SPI.h>

#include <lmic.h>
#include <hal/hal.h>

#include "config/pins.h"
#include "config/secrets.h"
#include "config/config.h"

#include "core/console.h"

#include "lora/lora_handler.h"
#include "lora/payload.h"

// =======================
// ETAT TTN
// =======================

static bool joined = false;

// =======================
// LMIC PINS
// =======================

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

// =======================
// EVENTS LMIC
// =======================

void onEvent(ev_t ev) {

    switch(ev) {

        case EV_JOINING:

            consoleInfo("TTN JOIN...");
            break;

        case EV_JOINED:

            consoleOk("TTN CONNECTE");

            joined = true;

            break;

        case EV_JOIN_FAILED:

            consoleWarn("TTN JOIN FAILED");

            joined = false;

            break;

        case EV_TXCOMPLETE:

            consoleInfo("Payload envoye");

            break;

        default:
            break;
    }
}

// =======================
// INIT LORA
// =======================

void initLoRa() {

    SPI.begin(
        SPI_SCK,
        SPI_MISO,
        SPI_MOSI
    );

    os_init();

    LMIC_reset();

    LMIC_startJoining();

    consoleOk("LoRa initialise");
}

// =======================
// LOOP LMIC
// =======================

void loopLoRa() {

    os_runloop_once();
}

// =======================
// ETAT JOIN
// =======================

bool isLoRaJoined() {

    return joined;
}

// =======================
// ENVOI DONNEES
// =======================

void envoyerDonnees() {

    if (!joined) {

        consoleWarn("TTN non connecte");
        return;
    }

    if (LMIC.opmode & OP_TXRXPEND) {

        consoleWarn("LoRa occupe");
        return;
    }

    uint8_t payload[WEATHER_PAYLOAD_SIZE];

    buildPayload(payload);

    LMIC_setTxData2(
        LORA_PORT,
        payload,
        WEATHER_PAYLOAD_SIZE,
        0
    );

    consoleInfo("Payload queue");
}