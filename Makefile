ESP_ROOT=/Applications/Code/Arduino.app/Contents/Java/hardware/esp8266com/esp8266

UPLOAD_PORT = /dev/ttyUSB0
BOARD = nodemcu
INCLUDE_VARIANT = nodemcu

LIBS = \
	   $(ESP_LIBS)/ESP8266WiFi \
	   $(ARDUINO_BASE)/libs/IRremoteESP8266/src

SKETCH = ir.ino

include $(ARDUINO_BASE)/tools/makeEspArduino/makeEspArduino.mk
