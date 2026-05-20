#include "core/globals.h"

volatile uint32_t impulsionsVent = 0;

volatile uint32_t rainTips = 0;

unsigned long lastSendMillis = 0;

bool alerteVent = false;

bool demandeEnvoiImmediate = false;