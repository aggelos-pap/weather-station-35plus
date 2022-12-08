#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI 9
#define OLED_CLK 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RESET 13

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

int measurePin = A5;
int ledPower = 7;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(ledPower, OUTPUT);
    display.begin(SSD1306_SWITCHCAPVCC);
    display.clearDisplay();
    display.display();
}

void loop()
{
    digitalWrite(ledPower, LOW);
    delayMicroseconds(280);

    voMeasured = analogRead(measurePin);

    delayMicroseconds(40);
    digitalWrite(ledPower, HIGH);
    delayMicroseconds(9680);

    calcVoltage = voMeasured * (5.0 / 1024);
    dustDensity = 0.17 * calcVoltage - 0.1;

    if (dustDensity < 0)
    {
        dustDensity = 0.00;
    }

    Serial.println("Raw Signal Value (0-1023):");
    Serial.println(voMeasured);

    Serial.println("Voltage:");
    Serial.println(calcVoltage);

    Serial.println("Dust Density:");
    Serial.println(dustDensity);

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(85, 22);
    display.println("Dust");
    display.setCursor(85, 38);
    display.println("Density");
    display.setTextSize(3);
    display.setCursor(0, 13);
    display.println(dustDensity);
    display.setCursor(6, 43);
    display.setTextSize(2);
    display.println("ug/m3");
    display.display();
    display.clearDisplay();

    delay(1000);
}