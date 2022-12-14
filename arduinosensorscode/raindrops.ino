/*
To test view the output, point a serial monitor such as Putty at your Arduino.

  - If the Sensor Board has water droplets on it; "case 0" will be activated and " Rain Warning " will be sent to the serial monitor.
  - If the Sensor Board is dry; "case 1" will be activated and " Not Raining " will be sent to the serial monitor.

*/

// lowest and highest sensor readings:
const int sensorMin = 0;    // sensor minimum
const int sensorMax = 1024; // sensor maximum

void setup()
{
    // initialize serial communication @ 9600 baud:
    Serial.begin(9600);
}
void loop()
{
    // read the sensor on analog A0:
    int sensorReading = analogRead(A0);
    // map the sensor range (four options):
    // ex: 'long int map(long int, long int, long int, long int, long int)'
    int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

    // range value:
    switch (range)
    {

    case 0: // Sensor getting wet
        Serial.println("Rain Warning");
        break;
    case 1: // Sensor dry
        Serial.println("Not Raining");
        break;
    }
    delay(1000); // delay between reads
}