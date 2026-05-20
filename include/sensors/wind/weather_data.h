#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include <Arduino.h>

struct WeatherData {

    // =======================
    // METEO
    // =======================

    float temperature;

    float humidity;

    float pressure;

    // =======================
    // VENT
    // =======================

    float windSpeed;

    uint8_t windDirection;

    // =======================
    // PLUIE
    // =======================

    float rainMM;
};

#endif