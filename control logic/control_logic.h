#ifndef CONTROL_LOGIC_H
#define CONTROL_LOGIC_H

void updateControl(float hum);
bool isFanOn();
bool isAlarmOn();

void setManualOverride(bool state);
void setManualLED(bool state);
bool getManualOverride();
bool getManualLED();

#endif
