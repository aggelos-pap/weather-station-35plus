import RPi.GPIO as GPIO

# Set up the GPIO pin for the sensor
rain_pin = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(rain_pin, GPIO.IN)

# Read the moisture level from the sensor
moisture_level = GPIO.input(rain_pin)

# Print the moisture level to the console
while True:
    print("Rain level:", rain_pin)
    GPIO.cleanup()

# Clean up the GPIO
# GPIO.cleanup()
