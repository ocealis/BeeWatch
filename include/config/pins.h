#ifndef PINS_H
#define PINS_H

// =======================
// LORA
// =======================

#define LORA_NSS   5

#define LORA_RST   14

#define LORA_DIO0  2

#define LORA_DIO1  25

#define LORA_DIO2  26

// =======================
// SPI
// =======================

#define SPI_SCK    18

#define SPI_MISO   19

#define SPI_MOSI   23

// =======================
// I2C - BME280 + SHT31
// =======================

#define I2C_SDA    21

#define I2C_SCL    22

#undef BME280_ADDRESS

#define SHT31_ADDRESS   0x44

// =======================
// CAPTEURS VENT
// =======================

#define ANEMO_PIN      32

#define GIROUETTE_PIN  33

// =======================
// CAPTEUR PLUIE
// =======================

#define RAIN_PIN       27

#endif