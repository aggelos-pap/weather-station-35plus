#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_BME280.h>

Adafruit_ST7735 tft = Adafruit_ST7735(10, 9, 8);
Adafruit_BME280 bme;

void setup()
{
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST7735_BLACK);
  Wire.begin();
  bme.begin();
}

void loop()
{
  // Measure temperature, pressure, and humidity with BME280 sensor
  float temperature = bme.readTemperature();
  float pressure = bme.readPressure();
  float humidity = bme.readHumidity();

  // Display measurements on Adafruit 1.54 TFT screen
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.println("Temperature: " + String(temperature) + " C");
  tft.println("Pressure: " + String(pressure) + " hPa");
  tft.println("Humidity: " + String(humidity) + " %");
  delay(1000);
}