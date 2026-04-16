#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

void mqtt_init();
void mqtt_loop();
void mqtt_publish_humidity(float hum);
void mqtt_publish_alarm(bool alarm);
void mqtt_subscribe();

#endif