#ifndef PCF8574_H
#define PCF8574_H

#include <Arduino.h>
#include "sensors/i2c/pcf8574.h"
#include <Wire.h>

bool initPCF8574(uint8_t adresse) {
    Wire.beginTransmission(adresse);
    return Wire.endTransmission() == 0;
}

bool readPCF8574(uint8_t adresse, uint8_t &valeur) {
    Wire.requestFrom(adresse, (uint8_t)1);
    if (Wire.available()) {
        valeur = Wire.read();
        return true;
    }
    return false;
}

void afficheLes8bitsDeLaValeur(uint8_t valeur) {
    for (int i = 7; i >= 0; i--) {
        Serial.print((valeur >> i) & 1);
    }
    Serial.println();
}

#endif