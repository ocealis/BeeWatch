#include "sensors/weather/sht31_sensor.h"

#include <Wire.h>

#include <Adafruit_SHT31.h>

#include "config/pins.h"

Adafruit_SHT31 sht31 =
    Adafruit_SHT31();

bool shtFound = false;

bool initSHT31() {

    shtFound = sht31.begin(
        SHT31_ADDRESS
    );

    if (shtFound) {

        Serial.println(
            "[SHT31] OK"
        );

    } else {

        Serial.println(
            "[SHT31] NOT FOUND"
        );
    }

    return shtFound;
}

float getSHT31Temperature() {

    if (!shtFound) {
        return 0;
    }

    return sht31.readTemperature();
}

float getSHT31Humidity() {

    if (!shtFound) {
        return 0;
    }

    return sht31.readHumidity();
}