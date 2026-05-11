#pragma once

#include <Arduino.h>

bool initBME280();

float getBME280Temperature();

float getBME280Humidity();

float getBME280Pressure();