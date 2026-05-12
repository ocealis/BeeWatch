#ifndef PCF8574_H
#define PCF8574_H

#include <Wire.h>
#include <Arduino.h>

void initPCF8574(uint8_t adresse);
void readPCF8574(uint8_t adresse, uint8_t &valeur);
void afficheLes8bitsDeLaValeur(uint8_t valeur);

#endif