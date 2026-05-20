#include <Arduino.h>

#include "config/pins.h"
#include "config/constants.h"
#include "core/globals.h"

volatile unsigned long lastRainInterrupt = 0;

const float MM_PER_TIP = 0.2794;

void IRAM_ATTR onRainTip() {

    unsigned long now = micros();

    if (now - lastRainInterrupt > debounceRainUs) {

        rainTips++;

        lastRainInterrupt = now;
    }
}

void initRainGauge() {

    pinMode(RAIN_PIN, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(RAIN_PIN),
        onRainTip,
        FALLING
    );
}

float getRainMM() {

    return rainTips * MM_PER_TIP;
}