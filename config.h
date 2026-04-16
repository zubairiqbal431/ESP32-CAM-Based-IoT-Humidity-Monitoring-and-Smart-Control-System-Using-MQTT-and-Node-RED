#ifndef CONFIG_H
#define CONFIG_H

// ---------------- WIFI ----------------
#define WIFI_SSID "your wifi name"
#define WIFI_PASS "wifi password" //this suport only 2.4 GH band so change the wifi band from 5 to 2.4 GH

// ---------------- MQTT ----------------
#define MQTT_SERVER "broker.hivemq.com"

// ---------------- TOPICS ----------------
#define TOPIC_HUMIDITY "zubair/iot/humidity"
#define TOPIC_LED_CONTROL "zubair/iot/led/control"
#define TOPIC_ALARM "zubair/iot/alarm"

// ---------------- PINS ----------------
#define DHT_PIN   15
#define LED_PIN   4
#define ALARM_PIN 13

#endif