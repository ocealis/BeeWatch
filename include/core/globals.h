#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

extern volatile uint32_t impulsionsVent;

extern volatile uint32_t rainTips;

extern unsigned long lastSendMillis;

extern bool alerteVent;

extern bool demandeEnvoiImmediate;

#endif