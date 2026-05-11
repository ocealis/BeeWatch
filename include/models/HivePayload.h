#ifndef HIVEPAYLOAD_H
#define HIVEPAYLOAD_H

#include <Arduino.h>

class HivePayload {
public:
    HivePayload();
    void buildPayload(uint8_t *payload);
};

#endif