#include <Arduino.h>

#include "config/constants.h"
#include "config/config.h"

#include "core/console.h"
#include "core/globals.h"

#include "models/weather_data.h"

#include "sensors/weather/bme280_sensor.h"
#include "sensors/weather/sht31_sensor.h"
#include "sensors/weather/rain_gauge.h"

#include "sensors/wind/anemometer.h"
#include "sensors/wind/wind_vane.h"

#include "lora/lora_handler.h"

// =======================
// DONNEES METEO
// =======================

WeatherData meteo;

// =======================
// SETUP
// =======================

void setup() {

    Serial.begin(115200);

    delay(1000);

    consoleHeader();

    consoleSection("CAPTEURS");

    #if USE_BME280
        initBME280();
    #endif

    #if USE_SHT31
        initSHT31();
    #endif

    #if USE_RAIN_GAUGE
        initRainGauge();
    #endif

    initAnemometer();

    consoleOk("Capteurs initialises");

    consoleSection("LORAWAN");

    initLoRa();
}

// =======================
// LOOP
// =======================

void loop() {

    loopLoRa();

    unsigned long now = millis();

    if (
        now - lastSendMillis >= TX_INTERVAL ||
        demandeEnvoiImmediate
    ) {

        lastSendMillis = now;

        demandeEnvoiImmediate = false;

        // =======================
        // BME280
        // =======================

        #if USE_BME280

            meteo.temperature =
                getBME280Temperature();

            meteo.humidity =
                getBME280Humidity();

            meteo.pressure =
                getBME280Pressure();

        #endif

        // =======================
        // SHT31
        // =======================

        #if USE_SHT31

            meteo.shtTemperature =
                getSHT31Temperature();

            meteo.shtHumidity =
                getSHT31Humidity();

        #endif

        // =======================
        // VENT
        // =======================

        meteo.windSpeed =
            getWindSpeed();

        meteo.windDirection =
            getWindDirection();

        // =======================
        // PLUIE
        // =======================

        #if USE_RAIN_GAUGE

            meteo.rainMM =
                getRainMM();

        #endif

        // =======================
        // CONSOLE
        // =======================

        consoleSection("METEO");

        consoleData(
            "Temperature",
            String(meteo.temperature, 2),
            "C"
        );

        consoleData(
            "Humidite",
            String(meteo.humidity, 1),
            "%"
        );

        consoleData(
            "Pression",
            String(meteo.pressure, 1),
            "hPa"
        );

        consoleData(
            "Vent",
            String(meteo.windSpeed, 1),
            "km/h"
        );

        consoleData(
            "Direction",
            String(meteo.windDirection)
        );

        consoleData(
            "Pluie",
            String(meteo.rainMM, 2),
            "mm"
        );

        // =======================
        // ALERTE VENT
        // =======================

        if (meteo.windSpeed >= ALERTE_VENT_KMH) {

            alerteVent = true;

            consoleWarn("ALERTE VENT");
        }
        else {

            alerteVent = false;
        }

        // =======================
        // ENVOI TTN
        // =======================

        if (isLoRaJoined()) {

            envoyerDonnees();
        }
        else {

            consoleWarn("TTN non connecte");
        }
    }
}