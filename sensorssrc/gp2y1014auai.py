import RPi.GPIO as GPIO

# Set up the GPIO pin for the sensor
dust_pin = 17
GPIO.setmode(GPIO.BCM)
GPIO.setup(dust_pin, GPIO.IN)

# Read the dust concentration from the sensor
dust_concentration = GPIO.input(dust_pin)

# Print the dust concentration to the console
print("Dust concentration:", dust_concentration)

# Clean up the GPIO
GPIO.cleanup()
