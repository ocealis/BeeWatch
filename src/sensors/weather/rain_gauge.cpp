#include "sensors/weather/rain_gauge.h"

#include <Arduino.h>

#include "config/pins.h"

volatile uint32_t rainTips = 0;

// =======================
// INTERRUPTION
// =======================

void IRAM_ATTR onRainTip() {

    rainTips++;
}

// =======================
// INITIALISATION
// =======================

void initRainGauge() {

    pinMode(
        RAIN_PIN,
        INPUT_PULLUP
    );

    attachInterrupt(
        digitalPinToInterrupt(
            RAIN_PIN
        ),
        onRainTip,
        FALLING
    );

    Serial.println(
        "[RAIN] OK"
    );
}

// =======================
// PLUIE MM
// =======================

float getRainMm() {

    // 1 basculement = 0.2794 mm
    return rainTips * 0.2794;
}   