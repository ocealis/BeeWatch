#include <Wire.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include "config/pins.h"

#include "core/console.h"

Adafruit_BME280 bme;

bool initBME280() {

    Wire.begin(
        I2C_SDA,
        I2C_SCL
    );

    if (!bme.begin(0x76)) {

        consoleWarn("BME280 absent");

        return false;
    }

    consoleOk("BME280 detecte");

    return true;
}

float getBME280Temperature() {

    return bme.readTemperature();
}

float getBME280Humidity() {

    return bme.readHumidity();
}

float getBME280Pressure() {

    return bme.readPressure() / 100.0F;
}