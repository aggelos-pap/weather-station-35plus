#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_ST77xx.h>

#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <locale.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>             // Arduino SPI library





#include <stdint.h>

#define rainfall A0

int value;

int set = 10;


// ST7789 TFT module connections
#define TFT_CS 10  // define chip select pin
#define TFT_DC 9   // define data/command pin
#define TFT_RST -1 // define reset pin, or set to -1 and connect to Arduino RESET pin



#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

// Initialize Adafruit ST7789 TFT library
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
int tempTemperatureReading = 0;
int tempPressureReading = 0;
int tempHumidityReading = 0;

void setup(void)
{
 

    Serial.begin(9600);

    pinMode(rainfall, INPUT);

    Serial.begin(9600);

    if (!bme.begin(0x76))
    {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1)
            ;
    }
    Serial.begin(9600);
    Serial.print(F("Hello! ST77xx TFT Test"));

    // if the display has CS pin try with SPI_MODE0
    tft.init(240, 240, SPI_MODE2); // Init ST7789 display 240x240 pixel

    // if the screen is flipped, remove this command
    tft.setRotation(2);
    // tft.setTextFont(1);
    //tft.setFont(&FreeSans9pt7b);

    Serial.println(F("Initialized"));

    uint16_t time = millis();
    tft.fillScreen(ST77XX_WHITE);
    time = millis() - time;

    Serial.println(time, DEC);

    delay(500);


    // tft.fillScreen(ST77XX_BLACK);

}

void loop()
{
  Serial.print(value);
    // Important
  Serial.print("working");
    tft.setCursor(10, 10);
    tft.setTextColor(ST77XX_BLUE);
    tft.setTextSize(2);
    
    tft.println("IEK AIGALEW");
    tft.println();
    if (tempTemperatureReading != bme.readTemperature())
    {
        tempTemperatureReading = bme.readTemperature();
        tft.setCursor(5, 70);
        tft.setTextColor(ST77XX_BLUE, ST77XX_WHITE);
        tft.print(tempTemperatureReading);
        tft.print("C");
    }
    // tft.print(bme.readTemperature());
    // tft.print("C");
    tft.println();
    if (tempPressureReading != bme.readPressure())
    {
        tempPressureReading = (bme.readPressure() / 100.0F);
        tft.setCursor(5, 100);
        tft.setTextColor(ST77XX_BLUE, ST77XX_WHITE);
        tft.print(tempPressureReading);
        tft.print("Hpa");
    }

    tft.println();

    if (tempHumidityReading != bme.readHumidity())
    {
        tempHumidityReading = bme.readHumidity();
        tft.setCursor(5, 130);
        tft.setTextColor(ST77XX_BLUE, ST77XX_WHITE);
        tft.print(tempHumidityReading);
        tft.print("%");
    }
    tft.println();

    value = analogRead(rainfall);

    value = map(value, 0, 1023, 225, 0);
    //  Serial.println(value);
    Serial.println(value);

    //  Serial.println(value);

    if (value >= 60)
    {
        
        tft.setCursor(5, 160);
        tft.setTextColor(ST77XX_BLUE, ST77XX_WHITE);
        tft.println("It is Raining");
    }
    else
    {
        tft.setCursor(5, 160);
        tft.setTextColor(ST77XX_BLUE, ST77XX_WHITE);
        tft.println("Not   raining");
    }

    delay(1000);
}

