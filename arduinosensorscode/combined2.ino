#include <ESP8266WiFi.h>
#include <BME3-1_Mikroe_1978.h>
#include <APDS-9930.h>
#include <RaindropsForArduino.h>
#include <SharpGP2Y1014AU.h>
#include <Adafruit_ST7789.h>

// WiFi credentials
const char *ssid = "your_ssid";
const char *password = "your_password";

// TFT display dimensions
const int TFT_WIDTH = 128;
const int TFT_HEIGHT = 128;

// TFT display object
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

// BME sensor object
BME3 - 1_Mikroe_1978 bme;

// APDS sensor object
APDS - 9930 apds;

// Raindrops sensor object
RaindropsForArduino raindrops;

// Sharp sensor object
SharpGP2Y1014AU sharp;

void setup()
{
    // Initialize serial communication
    Serial.begin(115200);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }

    // Initialize TFT display
    tft.init(TFT_WIDTH, TFT_HEIGHT);
    tft.setRotation(3);

    // Initialize BME sensor
    bme.begin();

    // Initialize APDS sensor
    apds.begin();

    // Initialize Raindrops sensor
    raindrops.begin();

    // Initialize Sharp sensor
    sharp.begin();
}

void loop()
{
    // Measure humidity, temperature, and pressure
    float humidity = bme.readHumidity();
    float temperature = bme.readTemperature();
    float pressure = bme.readPressure();

    // Measure distance and brightness
    float distance = apds.readDistance();
    float brightness = apds.readBrightness();

    // Check if it is raining
    bool isRaining = raindrops.isRaining();

    // Measure dust percentage and quality of air
    float dustPercentage = sharp.readDustPercentage();
    float airQuality = sharp.readAirQuality();

    // Display measurements on TFT display
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(0, 0);
    tft.setTextColor(ST77XX_WHITE);
    tft.print("Humidity: ");
    tft.print(humidity);
    tft.println(" %");
    tft.print("Temperature: ");
    tft.print(temperature);
    tft.println(" C");
    tft.print("Pressure: ");
    tft.print(pressure);
    tft.println(" Pa");
    tft.print("Distance: ");
    tft.print(distance);
    tft.println(" cm");
    tft.print("Brightness: ");
    tft.print(brightness);
    tft.println(" lux");
    tft.print("Is it raining? ");
    tft.println(isRaining ? "Yes" : "No");
    tft.print("Dust percentage: ");
    tft.print(dustPercentage);
    tft.println(" %");
    tft.print("Air quality: ");
    tft.print(airQuality);
    tft.println(" ppm");

    // Set TFT brightness based on distance
    if (distance < 200)
    {
        tft.setBrightness(255);
    }
    else
    {
        tft.setBrightness(128);
    }

    delay(1000);
}
