#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <APDS9930.h>

Adafruit_ST7735 tft = Adafruit_ST7735(10, 9, 8);
APDS9930 proximitySensor;

void setup()
{
    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(ST7735_BLACK);
    Wire.begin();
    proximitySensor.begin();
}

void loop()
{
    // Measure distance with APDS9930 proximity sensor
    float distance = proximitySensor.getDistance();
    if (distance < 200)
    { // Increase screen brightness if object is closer than 2 meters
        tft.setBrightness(255);
    }
    else
    {
        tft.setBrightness(128);
    }

    // Display distance on Adafruit 1.54 TFT screen
    tft.setCursor(0, 0);
    tft.setTextSize(1);
    tft.println("Distance: " + String(distance) + " cm");
    delay(1000);
}