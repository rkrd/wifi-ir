PWD=$(shell pwd)
ESP_ROOT=/opt/arduino/hardware/esp8266com/esp8266
include $(ARDUINO_BASE)/tools/makeEspArduino/makeEspArduino.mk

LIBS = \
	   $(ESP_LIBS)/ESP8266WiFi \
	   $(PWD)/IRremoteESP8266

SKETCH = ir.ino

UPLOAD_PORT = /dev/ttyUSB0
#BOARD = nodemcu
#INCLUDE_VARIANT = nodemcu
