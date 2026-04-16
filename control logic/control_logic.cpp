#include "config.h"

bool fanState = false;
bool alarmState = false;

bool manualOverride = false;
bool manualLEDState = false;

void updateControl(float hum) {

    if (hum < 60) {
        fanState = false;
        alarmState = false;
    }
    else if (hum >= 60 && hum <= 80) {
        fanState = true;
        alarmState = false;
    }
    else if (hum > 80) {
        fanState = true;
        alarmState = true;
    }
}

bool isFanOn() {
    return fanState;
}

bool isAlarmOn() {
    return alarmState;
}

// ---------------- MANUAL CONTROL ----------------
void setManualOverride(bool state) {
    manualOverride = state;
}

void setManualLED(bool state) {
    manualLEDState = state;
}

bool getManualOverride() {
    return manualOverride;
}

bool getManualLED() {
    return manualLEDState;
}
