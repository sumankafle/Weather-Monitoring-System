#include "SensorManager.hpp"
#include "Config.hpp"
#include <Arduino.h>

SensorManager::SensorManager() : dht(TEMP_HUM_SENSOR_PIN, DHT11), temperature(0), humidity(0), pressure(0), AQI(0), rainfall(0) {}

void SensorManager::begin() {
    dht.begin();
    pinMode(RAIN_SENSOR_PIN, INPUT);
    pinMode(AIR_SENSOR_PIN, INPUT);

    while(!bmp.begin()) {
        Serial.println("BMP085 sensor not found, check wiring!");
        delay(1000);
    }
}

void SensorManager::readTemperature() {
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    temperature = event.temperature;
}

void SensorManager::readHumidity() {
    sensors_event_t event;
    dht.humidity().getEvent(&event);
    humidity = event.relative_humidity;
}

void SensorManager::readPressure() {
    pressure = bmp.readPressure() / 100.0; // Pa -> mbar
}

void SensorManager::readAirQuality() {
    int mq135Raw = analogRead(AIR_SENSOR_PIN);
    float mq135PPM = mq135Raw * (5.0 / 1023.0) * 20.0;
    AQI = map(mq135PPM, 0, 500, 0, 300);
}

void SensorManager::readRainfall() {
    rainfall = digitalRead(RAIN_SENSOR_PIN) == HIGH ? 0 : 1;
}

void SensorManager::readSensors() {
    readTemperature();
    readHumidity();
    readPressure();
    readAirQuality();
    readRainfall();
}

float SensorManager::getTemperature() const { return temperature; }
float SensorManager::getHumidity() const { return humidity; }
float SensorManager::getPressure() const { return pressure; }
int SensorManager::getAQI() const { return AQI; }
int SensorManager::getRainfall() const { return rainfall; }
