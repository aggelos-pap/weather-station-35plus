from Adafruit_Python_ST7789 import ST7789
import time

# Initialize the ST7789 display using the default HSPI configuration.
disp = ST7789.ST7789(
    rst=24,  # Reset pin (optional)
    dc=25,   # Data/command pin
    spi=SPI.SpiDev(0, 0),  # SPI device
    width=240,  # Display width
    height=240,  # Display height
    bgr=True   # Swap red and blue channels
)

# Clear the display.
disp.clear()

# Draw a red rectangle.
disp.rect(10, 10, 50, 50, ST7789.RED, filled=True)

# Draw a green circle.
disp.circle(100, 100, 25, ST7789.GREEN, filled=True)

# Draw a blue line.
disp.line(150, 10, 200, 60, ST7789.BLUE)

# Display the shapes for 5 seconds.
time.sleep(5)

# Turn off the display.
disp.display_off()
