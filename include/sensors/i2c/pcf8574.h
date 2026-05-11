#ifndef PCF8574_H
#define PCF8574_H

#include <Wire.h>

void initPCF8574(uint8_t adresse);
void readPCF8574(uint8_t adresse, byte &valeur);
void afficheLes8bitsDeLaValeur(byte valeur);

#endif