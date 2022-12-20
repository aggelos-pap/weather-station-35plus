import time
import Adafruit_GPIO as GPIO
import Adafruit_GPIO.SPI as SPI
import Adafruit_SSD1351

# Set up the display
disp = Adafruit_SSD1351.SSD1351_240x240(
    rst=None, dc=23, spi=SPI.SpiDev(0, 0, max_speed_hz=64000000))

# Initialize the display
disp.begin()

# Clear the display
disp.clear()

# Draw a red circle on the display
disp.drawCircle(120, 120, 50, Adafruit_SSD1351.RED)

# Display the image
disp.display()

# Wait for 5 seconds
time.sleep(5)

# Clear the display
disp.clear()

# Display text on the display
disp.drawText(50, 50, "Hello, World!", Adafruit_SSD1351.WHITE)

# Display the text
disp.display()

# Wait for 5 seconds
time.sleep(5)

# Clear the display
disp.clear()

# Clean up the display
disp.end()
