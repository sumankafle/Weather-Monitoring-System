#pragma once
#include <WiFiS3.h>
#include "SensorManager.hpp"

class WebServer {
public:
    WebServer(SensorManager& sensors);
    void begin();
    void handleClient();

private:
    WiFiServer server;
    SensorManager& sensorManager;
    void sendJSON(WiFiClient &client);
    void sendWebPage(WiFiClient &client);
};
