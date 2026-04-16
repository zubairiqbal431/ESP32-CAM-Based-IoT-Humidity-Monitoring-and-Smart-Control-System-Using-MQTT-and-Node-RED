#include "DHTesp.h"
#include "config.h"

DHTesp dht;

void sensor_init() {
    dht.setup(DHT_PIN, DHTesp::DHT22);
}

float getHumidity() {
    TempAndHumidity data = dht.getTempAndHumidity();
    return data.humidity;
}