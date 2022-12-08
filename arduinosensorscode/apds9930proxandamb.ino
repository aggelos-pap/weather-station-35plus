/*
APDS-9930-Proximity-And-Ambient-Light
modified on 02 Nov 2020
by Amir Mohammad Shojaee @ Electropeak
Home

Based on Github.com Library Example
*/

#define DUMP_REGS

#include <Wire.h>
#include <APDS9930.h>

// Global Variables
APDS9930 apds = APDS9930();
float ambient_light = 0; // can also be an unsigned long

void setup()
{

    // Initialize Serial port
    Serial.begin(9600);
    Serial.println();

    // Initialize APDS-9930 (configure I2C and initial values)
    if (apds.init())
    {
        Serial.println(F("APDS-9930 initialization complete"));
    }
    else
    {
        Serial.println(F("Something went wrong during APDS-9930 init!"));
    }

    // Start running the APDS-9930 light sensor (no interrupts)
    if (apds.enableLightSensor(false))
    {
        Serial.println(F("Light sensor is now running"));
    }
    else
    {
        Serial.println(F("Something went wrong during light sensor init!"));
    }

    // Wait for initialization and calibration to finish
    delay(500);
}

void loop()
{

    // Read the light levels (ambient, red, green, blue)
    if (!apds.readAmbientLightLux(ambient_light))
    {
        Serial.println(F("Error reading light values"));
    }
    else
    {
        Serial.print(F("Ambient: "));
        Serial.println(ambient_light);
    }

    // Wait 1 second before next reading
    delay(1000);
}