#ifndef BME280_SENSOR_H
#define BME280_SENSOR_H

bool initBME280();

float getBME280Temperature();

float getBME280Humidity();

float getBME280Pressure();

#endif