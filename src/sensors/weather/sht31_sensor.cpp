#include <Wire.h>
#include <Adafruit_SHT31.h>

#include "config/pins.h"
#include "core/console.h"

Adafruit_SHT31 sht31;

bool initSHT31() {

    Wire.begin(I2C_SDA, I2C_SCL);

    if (!sht31.begin(SHT31_ADDRESS)) {

        consoleWarn("SHT31 absent");
        return false;
    }

    consoleOk("SHT31 detecte");

    return true;
}

float getSHT31Temperature() {

    return sht31.readTemperature();
}

float getSHT31Humidity() {

    return sht31.readHumidity();
}