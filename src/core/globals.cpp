#include "core/globals.h"

// =======================
// VENT
// =======================

volatile uint32_t impulsionsVent = 0;

unsigned long lastSendMillis = 0;

// =======================
// ALERTES
// =======================

bool alerteVent = false;

bool demandeEnvoiImmediate = false;