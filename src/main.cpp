#include <Arduino.h>

#include <Wire.h>

#include "core/console.h"

#include "sensors/weather/bme280_sensor.h"

#include "sensors/weather/sht31_sensor.h"

#include "sensors/weather/rain_gauge.h"

#include "sensors/wind/anemometer.h"

#include "sensors/wind/wind_vane.h"

#include "lora/lora_handler.h"

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
}

void loop() {

    loopLoRa();
}