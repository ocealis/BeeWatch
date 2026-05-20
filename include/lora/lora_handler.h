#pragma once

#include <Arduino.h>

// =======================
// INITIALISATION LORA
// =======================

void initLoRa();

// =======================
// BOUCLE LMIC
// =======================

void loopLoRa();

// =======================
// ENVOI DONNEES
// =======================

void envoyerDonnees();

// =======================
// ETAT TTN
// =======================

bool isLoRaJoined();