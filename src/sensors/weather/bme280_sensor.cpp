#include "sensors/weather/bme280_sensor.h"

#include <Wire.h>

#include <Adafruit_BME280.h>

#include "config/pins.h"

#define BME280_ADDRESS 0x76

Adafruit_BME280 bme;

bool bmeFound = false;

bool initBME280() {

    bmeFound = bme.begin(
        BME280_ADDRESS
    );

    if (bmeFound) {

        Serial.println(
            "[BME280] OK"
        );

    } else {

        Serial.println(
            "[BME280] NOT FOUND"
        );
    }

    return bmeFound;
}

float getBME280Temperature() {

    if (!bmeFound) {
        return 0;
    }

    return bme.readTemperature();
}

float getBME280Humidity() {

    if (!bmeFound) {
        return 0;
    }

    return bme.readHumidity();
}

float getBME280Pressure() {

    if (!bmeFound) {
        return 0;
    }

    return bme.readPressure()
           / 100.0F;
}