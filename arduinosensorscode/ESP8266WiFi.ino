#include <ESP8266WiFi.h>

const char *ssid = "YourWiFiNetworkName";
const char *password = "YourWiFiNetworkPassword";

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Connected to WiFi network");
}

void loop()
{
    Serial.print("Network name: ");
    Serial.println(WiFi.SSID());
    Serial.print("Network speed: ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
}