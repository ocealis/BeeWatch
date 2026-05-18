#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <Arduino.h>

// Taille payload météo
#define WEATHER_PAYLOAD_SIZE 10

void buildPayload(
    uint8_t *payload
);

#endif