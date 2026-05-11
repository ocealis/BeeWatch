#ifndef CONFIG_H
#define CONFIG_H

// =======================
// PROJET
// =======================

#define PROJECT_NAME "BeeWatch"

#define PROJECT_VERSION "1.0.0"

// =======================
// MODE DEBUG
// =======================

#define DEBUG_SERIAL true

// =======================
// CAPTEURS I2C
// =======================

#define USE_TCA9548A false

#define TCA9548A_ADDRESS 0x70

// =======================
// CAPTEURS METEO
// =======================

#define USE_BME280 true

#define USE_SHT31 true

#define USE_RAIN_GAUGE true

// =======================
// CAPTEURS RUCHE
// =======================

#define USE_HIVE_DATA true

// =======================
// LORA
// =======================

#define LORA_PORT 1

#endif