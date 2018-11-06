#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ESP8266WiFi.h>
#include "wifi.h"
#include "codes.h"
#include "html/gui.h"

uint16_t bits = 32U;
#define IR_SEND(BUTTON) do { irsend.sendNEC(BUTTON, bits); blink(); } while(0)

IRsend irsend(D2);
WiFiServer server(80);
char http_start[] = "<!DOCTYPE html> <html>\r\n";

void setup()
{
    irsend.begin();
    Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
    pinMode(D4, OUTPUT);
    pinMode(D3, INPUT);
    WiFi.mode(WIFI_STA);
}

void blink(void)
{
    digitalWrite(D4, LOW);
    delay(100);
    digitalWrite(D4, HIGH);
}

void loop()
{
    if (WiFi.status() != WL_CONNECTED) {
        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED) {
            Serial.print(".");
            delay(300);
            blink();
        }
        Serial.println("");
        Serial.println(WiFi.localIP());
        if (server.status() != 1) {
            Serial.println("Strating server");
            server.begin();
            delay(1000);
        }
    }

    WiFiClient client = server.available();
    if (!client) {
        //Serial.println("No client");
        delay(1);
        return;
    }
    
    String req = client.readStringUntil('\r');
    client.flush();
    Serial.println(req);

#define X(name) \
    if (req.indexOf(#name) != -1) \
        IR_SEND(name);

LIST_CONTROLS
#undef X

	// Add simple header so webapp is accepted.
	client.print("HTTP/1.1 200 OK\r\n\
		Server: espremote/0.0.1\r\n\
		Content-Type: text/html\r\n\
		Content-Length: ");
	client.print(strlen(http_start) + strlen(head_html) + strlen(body_html) + strlen("</html>\r\n"));
	client.print("\r\nConnection: close\r\n\
		Accept-Ranges: bytes\r\n\r\n");
    client.print(http_start);
    client.print(head_html);
    client.print(body_html);
    client.print("</html>\r\n");

    delay(10);
}
