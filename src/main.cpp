#include <Arduino.h>

#include <Wire.h>

#include "core/console.h"

#include "sensors/weather/bme280_sensor.h"

#include "sensors/weather/sht31_sensor.h"

#include "sensors/weather/rain_gauge.h"

#include "sensors/wind/anemometer.h"

#include "sensors/wind/wind_vane.h"

#include "lora/lora_handler.h"

#include "sensors/i2c/pcf8574.h"

#include "models/HivePayload.h"

#define PCF8574_ADDR 0x20 // Adresse I2C du module PCF8574

void scanI2C(); // Déclaration de la fonction avant setup()

void scanI2C() {
    Serial.println("Scanning I2C bus...");
    for (uint8_t addr = 1; addr < 127; addr++) {
        Wire.beginTransmission(addr);
        if (Wire.endTransmission() == 0) {
            Serial.print("Found I2C device at address 0x");
            Serial.println(addr, HEX);
        }
    }
    Serial.println("Scan complete.");
}

void setup() {

    Serial.begin(115200);

    delay(2000);

    consoleHeader();

    Wire.begin();

    Wire.setClock(100000); // Réduire la fréquence I2C à 100 kHz

    scanI2C(); // Scanner les périphériques I2C

    initBME280();

    initSHT31();

    initRainGauge();

    initAnemometer();

    initWindVane();

    initLoRa();

    Serial.println(F("Initialisation du PCF8574..."));

    if (!initPCF8574(PCF8574_ADDR)) {

        Serial.println("Erreur : PCF8574 non détecté !");

    } else {

        Serial.println("PCF8574 détecté avec succès.");

    }

    Serial.println(F("PCF8574 initialisé avec succès."));
}

void loop() {

    // Vérifier si une commande est reçue
    if (Serial.available() > 0) {
        String commande = Serial.readStringUntil('\n');
        commande.trim(); // Supprimer les espaces inutiles

        if (commande == "status") {
            Serial.println("[INFO] Système opérationnel.");
        } else if (commande == "pcf8574") {
            byte valeur;
            if (readPCF8574(PCF8574_ADDR, valeur)) {
                Serial.print("Valeur PCF8574 : ");
                afficheLes8bitsDeLaValeur(valeur);
            } else {
                Serial.println("Erreur de lecture du PCF8574.");
            }
        } else if (commande == "payload") {
            uint8_t payloadData[10];
            HivePayload payload;
            payload.buildPayload(payloadData);
            Serial.println("Payload construit :");
            for (int i = 0; i < 10; i++) {
                Serial.print(payloadData[i], HEX);
                Serial.print(" ");
            }
            Serial.println();
        } else {
            Serial.println("Commande inconnue.");
        }
    }

    // Appels existants
    loopLoRa();
    delay(1000);
}