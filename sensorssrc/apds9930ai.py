import smbus

# Set up the I2C bus and APDS-9930 sensor
bus = smbus.SMBus(1)
address = 0x39

# Enable proximity measurement
bus.write_byte_data(address, 0x00, 0x03)

# Read the proximity data from the sensor
proximity = bus.read_byte_data(address, 0x18)

# Print the proximity data to the console
print("Proximity:", proximity)
