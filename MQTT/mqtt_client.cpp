#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"
#include "control_logic.h"

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {

    String msg = "";
    for (int i = 0; i < length; i++) {
        msg += (char)payload[i];
    }

    if (String(topic) == TOPIC_LED_CONTROL) {

        setManualOverride(true);

        if (msg == "ON") setManualLED(true);
        else if (msg == "OFF") setManualLED(false);
    }
}

void mqtt_init() {
    client.setServer(MQTT_SERVER, 1883);
    client.setCallback(callback);
}

void mqtt_subscribe() {
    client.subscribe(TOPIC_LED_CONTROL);
}

void mqtt_loop() {

    if (!client.connected()) {

        while (!client.connected()) {
            client.connect("ESP32_CAM_HUMIDITY");
        }

        mqtt_subscribe();
    }

    client.loop();
}

void mqtt_publish_humidity(float hum) {
    client.publish(TOPIC_HUMIDITY, String(hum).c_str());
}

void mqtt_publish_alarm(bool alarm) {
    if (alarm) {
        client.publish(TOPIC_ALARM, "HIGH_HUMIDITY_ALERT");
    }
}
