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

#include "HivePayload.h"

#define PCF8574_ADDR 0x20 // Adresse I2C du module PCF8574

void setup() {

    Serial.begin(115200);

    delay(2000);

    consoleHeader();

    Wire.begin();

    initBME280();

    initSHT31();

    initRainGauge();

    initAnemometer();

    initWindVane();

    initLoRa();

    Serial.println(F("Initialisation du PCF8574..."));

    initPCF8574(PCF8574_ADDR);

    Serial.println(F("PCF8574 initialisé avec succès."));
}

void loop() {

    loopLoRa();

    byte valeur;

    readPCF8574(PCF8574_ADDR, valeur);

    afficheLes8bitsDeLaValeur(valeur);

    delay(1000);

    HivePayload payload;

    payload.buildPayload();

    Serial.println(F("Payload construit."));
}