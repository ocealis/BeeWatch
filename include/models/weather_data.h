#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include <Arduino.h>

struct WeatherData {

    float bmeTemperature;

    float bmeHumidity;

    float pressure;

    float shtTemperature;

    float shtHumidity;

    float windSpeed;

    uint16_t windDirection;

    float rainMm;

    bool valid;
};

#endif