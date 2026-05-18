#ifndef PCF8574_H
#define PCF8574_H

#include <Wire.h>
#include <Arduino.h>

bool initPCF8574(uint8_t addr);
bool readPCF8574(uint8_t addr, uint8_t &value);
void afficheLes8bitsDeLaValeur(uint8_t value);

#endif