#include <IRremoteESP8266.h>
#include <ESP8266WiFi.h>
#include "wifi.h"
#include "codes.h"

#define IR_SEND(BUTTON) do { irsend.sendLG(BUTTON, 32); blink(); } while(0)

IRsend irsend(4);
WiFiServer server(80);

void setup()
{
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
  pinMode(2, OUTPUT);
}

void blink(void)
{
    digitalWrite(2, LOW);
    digitalWrite(2, LOW);
    digitalWrite(2, LOW);
    delay(100);
    digitalWrite(2, HIGH);
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

    Serial.println("Server status:");
    Serial.println(server.status());

    WiFiClient client = server.available();
    if (!client) {
        Serial.println("No client");
        delay(1);
        return;
    }
    
    String req = client.readStringUntil('\r');
    client.flush();

#define X(name) \
    if (req.indexOf(#name) != -1) \
        IR_SEND(name);

LIST_CONTROLS
#undef X
    
    client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n \ 
            <!DOCTYPE HTML>\r\n<html>\r\n");

#define X(name) client.print("<a href=\""); \
    client.print("/"#name); \
    client.print("\">"); \
    client.print(#name); \
    client.print("</a><br />\r\n");

LIST_CONTROLS
#undef X

    client.print("</html>\n");
    delay(10);
}
