#include <Arduino.h>

#include "config/pins.h"

// =================================================
// GIROUETTE
// =================================================

int adcGirouette[8] = {

    200,
    600,
    1000,
    1400,
    1800,
    2200,
    2800,
    3400
};

uint16_t degresGirouette[8] = {

    0,
    45,
    90,
    135,
    180,
    225,
    270,
    315
};

const char* textesGirouette[8] = {

    "Nord",
    "Nord-Est",
    "Est",
    "Sud-Est",
    "Sud",
    "Sud-Ouest",
    "Ouest",
    "Nord-Ouest"
};

// =================================================
// INITIALISATION
// =================================================

void initWindVane() {

    pinMode(
        GIROUETTE_PIN,
        INPUT
    );

    Serial.println(
        "[GIROUETTE] OK"
    );
}

// =================================================
// LECTURE DIRECTION
// =================================================

uint8_t lireDirectionIndex() {

    int valeur =
        analogRead(GIROUETTE_PIN);

    int meilleurIndex = 0;

    int plusPetitEcart =
        abs(valeur - adcGirouette[0]);

    for (int i = 1; i < 8; i++) {

        int ecart =
            abs(valeur - adcGirouette[i]);

        if (ecart < plusPetitEcart) {

            plusPetitEcart = ecart;

            meilleurIndex = i;
        }
    }

    return meilleurIndex;
}

// =================================================
// DEGRÉS
// =================================================

uint16_t lireDirectionDegres() {

    return degresGirouette[
        lireDirectionIndex()
    ];
}

// =================================================
// TEXTE
// =================================================

const char* lireDirectionTexte() {

    return textesGirouette[
        lireDirectionIndex()
    ];
}