#include <WiFi.h>

#include "config.h"
#include "sensor_dht.h"
#include "mqtt_client.h"
#include "control_logic.h"

void setup() {

    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
    pinMode(ALARM_PIN, OUTPUT);

    digitalWrite(LED_PIN, LOW);
    digitalWrite(ALARM_PIN, LOW);

    // WiFi
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    sensor_init();
    mqtt_init();
}

void loop() {

    mqtt_loop();

    float hum = getHumidity();
    if (isnan(hum)) return;

    mqtt_publish_humidity(hum);

    updateControl(hum);

    digitalWrite(LED_PIN, isFanOn());
    digitalWrite(ALARM_PIN, isAlarmOn());

    mqtt_publish_alarm(isAlarmOn());

    delay(2000);
}