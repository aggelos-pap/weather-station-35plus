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
