#include "sensors/i2c/tca9548a.h"

#include <Wire.h>

#include "config/config.h"

bool initTCA9548A() {

    Wire.beginTransmission(
        TCA9548A_ADDRESS
    );

    bool ok =
        Wire.endTransmission() == 0;

    if (ok) {

        Serial.println(
            "[TCA9548A] OK"
        );

    } else {

        Serial.println(
            "[TCA9548A] NOT FOUND"
        );
    }

    return ok;
}

bool selectTCAChannel(
    uint8_t channel
) {

    if (channel > 7) {

        return false;
    }

    Wire.beginTransmission(
        TCA9548A_ADDRESS
    );

    Wire.write(
        1 << channel
    );

    return
        Wire.endTransmission() == 0;
}