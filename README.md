# Weather-Monitoring-System
Weather Monitoring System from my Bachelor 3rd sem Project. Later on I applied it in C++ during semester break.

# Author: Suman
# Created: 2022/02/25 
# Purpose: Compile and optionally upload C++ project for Arduino / Linux

**Try to reverse enginer *.ino file from internet into C++ project**

**source https://github.com/YogeshwaranP-05/IoT_Weather_Monitoring_System**

## Description
A C++ project for reading environmental sensors (temperature, humidity, pressure, air quality, rainfall) using Arduino UNO. The data is served via a local web dashboard and JSON API.

## Features
- Reads temperature, humidity, pressure, AQI, and rainfall
- Logs and serves real-time data via a web dashboard
- Built with C++ classes for sensors and web server
- Modular design for easy extension
- LED matrix shows WiFi connection status (optional)

## Project Structure
```

SensorDashboard/
├─ src/             # Source code (.cpp)
├─ include/         # Header files (.hpp)
├─ lib/             # Arduino or external libraries
├─ bin/             # Output binaries
├─ Makefile
└─ README.md

````

## Requirements
- gcc /g++
- Linux or Arduino environment
- Arduino libraries:

| Library            | GitHub / Source                                                    |
| ------------------ | ------------------------------------------------------------------ |
| Adafruit_BMP085    | [GitHub link](https://github.com/adafruit/Adafruit_BMP085_Library) |
| DHT / DHT_U        | [GitHub link](https://github.com/adafruit/DHT-sensor-library)      |
| WiFiS3             | Usually comes with Arduino S3 boards or Arduino Library Manager    |
| Arduino_LED_Matrix | Your LED Matrix library (from GitHub or vendor)                    |
````

SensorDashboard/
├─ lib/
│   ├─ Adafruit_BMP085/
│   ├─ DHT/
│   ├─ WiFiS3/
│   └─ Arduino_LED_Matrix/

````

## Build & Run
### On Linux :
```bash
make          # Build project
./bin/SensorDashboard
make clean    # Clean binaries
````

### On Arduino (optional):

```bash
make flash    # Upload using Arduino CLI (adjust port and board)
```

## Usage

* The web dashboard is accessible at `http://<DEVICE_IP>/`
* JSON API endpoint available at `http://<DEVICE_IP>/data`
## Test
It works 
