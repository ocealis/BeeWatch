#ifndef CONSOLE_H
#define CONSOLE_H

#include <Arduino.h>

void consoleHeader();

void consoleSection(const char* titre);

void consoleOk(const char* msg);

void consoleInfo(const char* msg);

void consoleWarn(const char* msg);

void consoleData(
    const char* label,
    const String& value,
    const char* unit = ""
);

#endif