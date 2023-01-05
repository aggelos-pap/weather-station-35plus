#include <Raindrops.h>

Raindrops rainSensor;

void setup()
{
    Serial.begin(9600);
    rainSensor.begin();
}

void loop()
{
    // Check for rain with rain sensor
    bool isRaining = rainSensor.isRaining();

    // Print rain status to serial monitor
    Serial.print("Is Raining: ");
    Serial.println(isRaining);

    delay(1000);
}