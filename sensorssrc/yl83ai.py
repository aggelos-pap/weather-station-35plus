import RPi.GPIO as GPIO
import time
# Set up the GPIO pin for the sensor
rain_pin = 18
# GPIO.setmode(GPIO.BCM)
GPIO.setmode(GPIO.BCM)
GPIO.setup(rain_pin, GPIO.IN)

# Read the moisture level from the sensor
rain_level = GPIO.input(rain_pin)

# is it raining?
# Set the rain threshold
rain_threshold = 50

# Check if it is raining based on the rain level
if rain_level > rain_threshold:
    print("It is raining.")
else:
    print("It is not raining.")

# rain %
pulse_start = 0
pulse_end = 0
while True:
    if GPIO.input(rain_pin) == 1:
        pulse_start = time.time()
    elif GPIO.input(rain_pin) == 0:
        pulse_end = time.time()
        break

# Calculate the rain level using the duty cycle of the PWM signal
duty_cycle = (pulse_end - pulse_start) / 20
rain_level = duty_cycle * 100
print("Rain level:", rain_level, "%")

# Print the moisture level to the console
while True:
    if (rain_level) == True:
        fun = str(rain_level)
        print(f'Its raining and the level is { fun}')
        GPIO.cleanup()

    else:
        fun = str(rain_level)
        print(f'Its not raining and the level is { fun} ')
        GPIO.cleanup()

# Clean up the GPIO
# GPIO.cleanup()
