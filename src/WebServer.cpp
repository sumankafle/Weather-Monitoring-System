#include "WebServer.hpp"
#include <Arduino.h>

WebServer::WebServer(SensorManager& sensors) : server(80), sensorManager(sensors) {}

void WebServer::begin() {
    server.begin();
}

void WebServer::handleClient() {
    WiFiClient client = server.available();
    if (client) {
        String request = client.readStringUntil('\r');
        client.flush();

        if (request.indexOf("GET / ") != -1) {
            sendWebPage(client);
        } else if (request.indexOf("GET /data") != -1) {
            sendJSON(client);
        }

        client.stop();
    }
}

void WebServer::sendJSON(WiFiClient &client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Connection: close");
    client.println();

    String json = "{\"temperature\":" + String(sensorManager.getTemperature()) +
                  ",\"humidity\":" + String(sensorManager.getHumidity()) +
                  ",\"pressure\":" + String(sensorManager.getPressure()) +
                  ",\"aqi\":" + String(sensorManager.getAQI()) +
                  ",\"rainfall\":" + String(sensorManager.getRainfall()) + "}";
    client.println(json);
}

void WebServer::sendWebPage(WiFiClient &client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    
    const char* html = "<!DOCTYPE html><html><head><title>Weather Dashboard</title></head><body><h1>Weather Dashboard</h1></body></html>";
    client.print(html);
}
