# -----------------------------
# Makefile for SensorDashboard
# -----------------------------

TARGET = SensorDashboard

CXX = g++
CXXFLAGS = -std=c++17 -Wall

INCLUDES = \
  -Ilib/Adafruit_BMP085 \
  -Ilib/DHT \
  -Ilib/Adafruit_Sensor \
  -Ilib/WiFiS3

LDFLAGS = -lwiringPi -lpthread

SRC_DIR = src
BUILD_DIR = obj
BIN_DIR = bin

SRCS = \
  $(SRC_DIR)/main.cpp \
  $(SRC_DIR)/SensorManager.cpp \
  $(SRC_DIR)/WebServer.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

BIN = $(BIN_DIR)/$(TARGET)

all: $(BIN)

$(BIN): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	@echo "Build complete: $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Clean complete"

.PHONY: all clean
