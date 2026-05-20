#include "core/console.h"

// =======================
// HEADER
// =======================

void consoleHeader() {

    Serial.println();

    Serial.println("=================================");

    Serial.println("        BEEWATCH v1.1");

    Serial.println("=================================");
}

// =======================
// SECTION
// =======================

void consoleSection(const char* titre) {

    Serial.println();

    Serial.print("[ ");

    Serial.print(titre);

    Serial.println(" ]");
}

// =======================
// OK
// =======================

void consoleOk(const char* msg) {

    Serial.print("[OK] ");

    Serial.println(msg);
}

// =======================
// INFO
// =======================

void consoleInfo(const char* msg) {

    Serial.print("[INFO] ");

    Serial.println(msg);
}

// =======================
// WARNING
// =======================

void consoleWarn(const char* msg) {

    Serial.print("[WARN] ");

    Serial.println(msg);
}

// =======================
// DATA
// =======================

void consoleData(
    const char* label,
    const String& value,
    const char* unit
) {

    Serial.print(label);

    Serial.print(" : ");

    Serial.print(value);

    if (strlen(unit) > 0) {

        Serial.print(" ");

        Serial.print(unit);
    }

    Serial.println();
}