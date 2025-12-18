#pragma once
#include <Adafruit_BMP085.h>
#include <DHT.h>
#include <DHT_U.h>

class SensorManager {
public:
    SensorManager();
    void begin();
    void readSensors();
    float getTemperature() const;
    float getHumidity() const;
    float getPressure() const;
    int getAQI() const;
    int getRainfall() const;

private:
    DHT_Unified dht;
    Adafruit_BMP085 bmp;
    float temperature;
    float humidity;
    float pressure;
    int AQI;
    int rainfall;

    void readTemperature();
    void readHumidity();
    void readPressure();
    void readAirQuality();
    void readRainfall();
};
