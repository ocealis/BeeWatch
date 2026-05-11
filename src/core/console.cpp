#include "core/console.h"
#include "config/pins.h"

void consoleHeader() {

  Serial.println();
  Serial.println("╔══════════════════════════════════════════════╗");
  Serial.println("║          BEEWATCH - RUCHE CONNECTÉE          ║");
  Serial.println("║        ESP32 + RFM95W + LoRaWAN TTN          ║");
  Serial.println("╚══════════════════════════════════════════════╝");
}

void consoleSection(const char* titre) {

  Serial.println();
  Serial.println("──────────────────────────────────────────────");
  Serial.print("▶ ");
  Serial.println(titre);
  Serial.println("──────────────────────────────────────────────");
}

void consoleOk(const char* msg) {

  Serial.print("✅ ");
  Serial.println(msg);
}

void consoleInfo(const char* msg) {

  Serial.print("ℹ️  ");
  Serial.println(msg);
}

void consoleWarn(const char* msg) {

  Serial.print("⚠️  ");
  Serial.println(msg);
}