#include <Sharp_GP2Y1014AU.h>

Sharp_GP2Y1014AU dustSensor;

void setup()
{
    Serial.begin(9600);
    dustSensor.begin();
}

void loop()
{
    // Measure dust particles in air with Sharp GP2Y1014AU sensor
    float dustLevel = dustSensor.read();

    // Print dust level to serial monitor
    Serial.print("Dust Level: ");
    Serial.println(dustLevel);

    delay(1000);
}