#ifndef ANEMOMETER_H
#define ANEMOMETER_H

void initAnemometer();

float calculerVitesseVent(
    uint32_t impulsions,
    float tempsSecondes
);

#endif