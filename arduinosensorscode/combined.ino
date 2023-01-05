#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_BME280.h>
#include <Sharp_GP2Y1014AU.h>
#include <APDS9930.h>
#include <Raindrops.h>

Adafruit_ST7735 tft = Adafruit_ST7735(10, 9, 8);
Adafruit_BME280 bme;
Sharp_GP2Y1014AU dustSensor;
APDS9930 proximitySensor;
Raindrops rainSensor;

void setup()
{
    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(ST7735_BLACK);
    Wire.begin();
    bme.begin();
    dustSensor.begin();
    proximitySensor.begin();
    rainSensor.begin();
}

void loop()
{
    // Measure temperature, pressure, and humidity with BME280 sensor
    float temperature = bme.readTemperature();
    float pressure = bme.readPressure();
    float humidity = bme.readHumidity();

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

    // Check for rain with rain sensor
    bool isRaining = rainSensor.isRaining();

    // Measure dust particles in air with Sharp GP2Y1014AU sensor
    float dustLevel = dustSensor.read();

    // Display measurements on Adafruit 1.54 TFT screen
    tft.setCursor(0, 0);
    tft.setTextSize(1);
    tft.println("Temperature: " + String(temperature) + " C");
    tft.println("Pressure: " + String(pressure) + " hPa");
    tft.println("Humidity: " + String(humidity) + " %");
    tft.println("Distance: " + String(distance) + " cm");
    tft.println("Is Raining: " + String(isRaining));
    tft.println("Dust Level: " + String(dustLevel));
    delay(1000);
}