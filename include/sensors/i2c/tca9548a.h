#ifndef TCA9548A_H
#define TCA9548A_H

#include <Arduino.h>

bool initTCA9548A();

bool selectTCAChannel(
    uint8_t channel
);

#endif