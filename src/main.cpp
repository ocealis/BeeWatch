#include <Arduino.h>

#include "core/console.h"

#include "sensors/wind/anemometer.h"

#include "sensors/wind/wind_vane.h"

#include "lora/lora_handler.h"

void setup() {

    Serial.begin(115200);

    delay(2000);

    consoleHeader();

    initAnemometer();

    initLoRa();
}

void loop() {

    loopLoRa();
}