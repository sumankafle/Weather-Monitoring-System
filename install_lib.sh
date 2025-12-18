#!/bin/bash

set -e  # Exit immediately if a command fails

# Current directory lib folder
LIB_DIR="./lib"

echo "Creating lib directory"
mkdir -p "$LIB_DIR"
cd "$LIB_DIR"

echo "Downloading Adafruit BMP085..."
if [ ! -d "Adafruit-BMP085" ]; then
    git clone https://github.com/adafruit/Adafruit-BMP085-Library.git Adafruit-BMP085
else
    echo "Adafruit_BMP085 already exists, skipping"
fi

echo "Downloading DHT sensor library..."
if [ ! -d "DHT" ]; then
    git clone https://github.com/adafruit/DHT-sensor-library.git DHT
else
    echo "DHT already exists, skipping"
fi

echo "Downloading Adafruit Unified Sensor (dependency for DHT)..."
if [ ! -d "Adafruit_Sensor" ]; then
    git clone https://github.com/adafruit/Adafruit_Sensor.git Adafruit_Sensor
else
    echo "Adafruit_Sensor already exists, skipping"
fi

echo "Downloading WiFiS3..."
if [ ! -d "WiFiS3" ]; then
    git clone https://github.com/arduino/ArduinoCore-renesas.git WiFiS3
else
    echo "WiFiS3 already exists, skipping"
fi

echo "Downloading Arduino LED Matrix..."
if [ ! -d "Arduino_LED_Matrix" ]; then
    git clone https://github.com/arduino-libraries/Arduino_LED_Matrix.git Arduino_LED_Matrix
else
    echo "Arduino_LED_Matrix already exists, skipping"
fi

echo "***All libraries downloaded successfully!***"
exit 0