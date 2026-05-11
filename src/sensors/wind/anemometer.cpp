#include <Arduino.h>

#include "config/pins.h"

#include "config/constants.h"

#include "core/globals.h"

volatile unsigned long lastPulseUs = 0;

// =================================================
// INTERRUPTION ANÉMOMÈTRE
// =================================================

void IRAM_ATTR compterImpulsionVent() {

    unsigned long now = micros();

    if (now - lastPulseUs >= debounceUs) {

        impulsionsVent++;

        lastPulseUs = now;
    }
}

// =================================================
// INITIALISATION
// =================================================

void initAnemometer() {

    pinMode(
        ANEMO_PIN,
        INPUT_PULLUP
    );

    attachInterrupt(
        digitalPinToInterrupt(ANEMO_PIN),
        compterImpulsionVent,
        FALLING
    );
}

// =================================================
// CALCUL VITESSE
// =================================================

float calculerVitesseVent(
    uint32_t impulsions,
    float tempsSecondes
) {

    float frequenceHz =
        impulsions / tempsSecondes;

    return frequenceHz *
           FACTEUR_ANEMO;
}