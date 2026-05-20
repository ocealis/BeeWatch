#ifndef CONSTANTS_H
#define CONSTANTS_H

// =======================
// LORAWAN
// =======================

const unsigned long TX_INTERVAL =
    5UL * 60UL * 1000UL;

// =======================
// ANEMOMETRE
// =======================

const unsigned long debounceWindUs = 10000;

const float FACTEUR_ANEMO = 2.4;

// =======================
// PLUIE
// =======================

const unsigned long debounceRainUs = 30000;

// =======================
// ALERTES
// =======================

const float ALERTE_VENT_KMH = 70.0;

const float ALERTE_TEMPETE_KMH = 100.0;

#endif