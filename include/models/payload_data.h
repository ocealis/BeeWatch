#ifndef PAYLOAD_DATA_H
#define PAYLOAD_DATA_H

#include <Arduino.h>

struct PayloadData {

    uint8_t bytes[32];

    uint8_t size;
};

#endif