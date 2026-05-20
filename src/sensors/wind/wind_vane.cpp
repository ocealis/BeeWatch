#include <Arduino.h>

#include "config/pins.h"

#include "sensors/wind/wind_vane.h"

int adcValues[8] = {

    200,
    600,
    1000,
    1400,
    1800,
    2200,
    2800,
    3400
};

uint8_t getWindDirection() {

    int value = analogRead(GIROUETTE_PIN);

    int bestIndex = 0;

    int smallest = 5000;

    for (int i = 0; i < 8; i++) {

        int delta = abs(value - adcValues[i]);

        if (delta < smallest) {

            smallest = delta;

            bestIndex = i;
        }
    }

    return bestIndex;
}