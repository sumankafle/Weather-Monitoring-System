#include <Arduino.h>
#include "lib/Config.hpp"
#include "lib/SensorManager.hpp"
#include "lib/WebServer.hpp"
#include "Config.hpp"
#include "SensorManager.hpp"
#include "WebServer.hpp"

unsigned long lastSensorUpdate = 0;
unsigned long lastWiFiCheck = 0;

SensorManager sensors;
WebServer webServer(sensors);

void wifiConnect() {
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("WiFi module not found!");
        while(true);
    }

    Serial.print("Connecting to WiFi...");
    while (WiFi.begin(WIFI_SSID, WIFI_PASSWORD) != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("\nConnected!");
    Serial.println(WiFi.localIP());
}

void setup() {
    Serial.begin(115200);
    while(!Serial) {}
    sensors.begin();
    wifiConnect();
    webServer.begin();
}

void loop() {
    if (millis() - lastSensorUpdate >= SENSOR_UPDATE_INTERVAL) {
        lastSensorUpdate = millis();
        sensors.readSensors();
    }

    if (millis() - lastWiFiCheck >= WIFI_CHECK_INTERVAL) {
        lastWiFiCheck = millis();
        if (WiFi.status() != WL_CONNECTED) {
            Serial.println("WiFi disconnected, reconnecting...");
            wifiConnect();
        }
    }

    webServer.handleClient();
}
