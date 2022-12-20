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
        fun = str(rain_level)
        print(f'Its raining and the level is { fun}')
        GPIO.cleanup()
    else:
        fun = str(rain_level)
        print(f'Its not raining and the level is { fun} ')

# Clean up the GPIO
# GPIO.cleanup()
