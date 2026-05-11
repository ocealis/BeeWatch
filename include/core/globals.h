#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

// =======================
// VENT
// =======================

extern volatile uint32_t impulsionsVent;

extern unsigned long lastSendMillis;

// =======================
// ALERTES
// =======================

extern bool alerteVent;

extern bool demandeEnvoiImmediate;

#endif