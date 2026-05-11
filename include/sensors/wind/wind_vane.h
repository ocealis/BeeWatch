#ifndef WIND_VANE_H
#define WIND_VANE_H

#include <Arduino.h>

void initWindVane();

uint8_t lireDirectionIndex();

uint16_t lireDirectionDegres();

const char* lireDirectionTexte();

#endif