#include "models/HivePayload.h"

HivePayload::HivePayload() {
    // Constructeur par défaut
}

void HivePayload::buildPayload(uint8_t *payload) {
    // Exemple de construction de payload
    payload[0] = 0x01; // Exemple : identifiant de la ruche
    payload[1] = 0x02; // Exemple : état de la ruche
    payload[2] = 0x03; // Exemple : température
    payload[3] = 0x04; // Exemple : humidité
    payload[4] = 0x05; // Exemple : pression
}
