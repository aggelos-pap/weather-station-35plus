import RPi.GPIO as GPIO

# Set up the GPIO pin for the sensor
moisture_pin = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(moisture_pin, GPIO.IN)

# Read the moisture level from the sensor
moisture_level = GPIO.input(moisture_pin)

# Print the moisture level to the console
print("Moisture level:", moisture_level)

# Clean up the GPIO
GPIO.cleanup()
