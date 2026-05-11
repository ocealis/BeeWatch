#ifndef SECRETS_H
#define SECRETS_H

#include <Arduino.h>

#include <lmic.h>

extern const u1_t APPEUI[8];

extern const u1_t DEVEUI[8];

extern const u1_t APPKEY[16];

void os_getArtEui(u1_t* buf);

void os_getDevEui(u1_t* buf);

void os_getDevKey(u1_t* buf);

#endif