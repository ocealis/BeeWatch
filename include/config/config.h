#ifndef CONFIG_H
#define CONFIG_H

#define PROJECT_NAME "BeeWatch"

#define PROJECT_VERSION "1.1.0"

#define DEBUG_SERIAL 1

#define USE_TCA9548A 0

#define TCA9548A_ADDRESS 0x70

#define USE_BME280 1

#define USE_SHT31 1

#define USE_RAIN_GAUGE 1

#define USE_HIVE_DATA 1

const uint8_t LORA_PORT = 1;

#endif