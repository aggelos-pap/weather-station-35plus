import RPi.GPIO as GPIO
import time
Set up the GPIO pin for the sensor
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

rain %
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
GPIO.cleanup()


Clean up the GPIO
GPIO.cleanup()
# Newwwwwwww
# Set the GPIO mode to BCM
# GPIO.setmode(GPIO.BCM)

# # Set the GPIO pin for the rain sensor as an input
# rain_sensor_pin = 18
# GPIO.setup(rain_sensor_pin, GPIO.IN)
# led_pin = 17
# GPIO.setup(led_pin, GPIO.OUT)

# # Initialize a variable to store the rain level
# rain_level = 0

# # Main loop
# while True:
#     # Read the state of the rain sensor
#     rain_sensor_state = GPIO.input(rain_sensor_pin)

#     # If the rain sensor is triggered (i.e., it is raining), increase the rain level by 1
#     if rain_sensor_state == 0:
#         rain_level += 1
#     else:
#         GPIO.output(led_pin, False)

#     # Print the current rain level
#     print("Rain level:", rain_level)

#     # Wait for a moment before checking the rain sensor again
#     time.sleep(1)
