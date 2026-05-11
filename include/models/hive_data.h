#ifndef HIVE_DATA_H
#define HIVE_DATA_H

#include <Arduino.h>

struct HiveData {

    float temperature;

    float humidity;

    float weight;

    float battery;

    bool valid;
};

#endif