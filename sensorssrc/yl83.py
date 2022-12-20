import RPi.GPIO as GPIO

# Set up the GPIO pin for the sensor
rain_pin = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(rain_pin, GPIO.IN)

# Read the moisture level from the sensor
rain_level = GPIO.input(rain_pin)

# Print the moisture level to the console
while True:
    if (rain_level) == 1:
        print("Its raining, rain level is", (str)rain_level))
        GPIO.cleanup()
    else:
        print("No rain", (str)rain_level)

# Clean up the GPIO
# GPIO.cleanup()
