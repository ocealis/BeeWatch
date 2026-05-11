#include "lora/payload.h"

#include "sensors/weather/bme280_sensor.h"

#include "sensors/weather/sht31_sensor.h"

void buildPayload(uint8_t *payload) {

    float bmeTemp =
        getBME280Temperature();

    float bmeHum =
        getBME280Humidity();

    float pressure =
        getBME280Pressure();

    float shtTemp =
        getSHT31Temperature();

    float shtHum =
        getSHT31Humidity();

    int16_t t1 =
        bmeTemp * 100;

    uint16_t h1 =
        bmeHum * 100;

    int16_t t2 =
        shtTemp * 100;

    uint16_t h2 =
        shtHum * 100;

    uint16_t p =
        pressure;

    payload[0] =
        highByte(t1);

    payload[1] =
        lowByte(t1);

    payload[2] =
        highByte(h1);

    payload[3] =
        lowByte(h1);

    payload[4] =
        highByte(t2);

    payload[5] =
        lowByte(t2);

    payload[6] =
        highByte(h2);

    payload[7] =
        lowByte(h2);

    payload[8] =
        highByte(p);

    payload[9] =
        lowByte(p);
}