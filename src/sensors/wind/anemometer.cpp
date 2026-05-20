#include <Arduino.h>

#include "config/pins.h"
#include "config/constants.h"
#include "core/globals.h"

volatile unsigned long lastWindInterrupt = 0;

void IRAM_ATTR onWindPulse() {

    unsigned long now = micros();

    if (now - lastWindInterrupt > debounceWindUs) {

        impulsionsVent++;

        lastWindInterrupt = now;
    }
}

void initAnemometer() {

    pinMode(ANEMO_PIN, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(ANEMO_PIN),
        onWindPulse,
        FALLING
    );
}

float getWindSpeed() {

    static uint32_t oldImpulsions = 0;

    uint32_t current;

    noInterrupts();

    current = impulsionsVent;

    interrupts();

    uint32_t diff = current - oldImpulsions;

    oldImpulsions = current;

    return diff * FACTEUR_ANEMO;
}