import smbus2
import bme280

# Set up the I2C bus and BME280 sensor
port = 1
address = 0x76
bus = smbus2.SMBus(port)
calibration_params = bme280.load_calibration_params(bus, address)

# Read the temperature, humidity, and pressure from the sensor
data = bme280.sample(bus, address, calibration_params)
temperature = data.temperature
humidity = data.humidity
pressure = data.pressure

# Print the temperature, humidity, and pressure to the console
print("Temperature: {:.1f} C".format(temperature))
print("Humidity: {:.1f} %".format(humidity))
print("Pressure: {:.1f} hPa".format(pressure))
