import serial

# Set up the serial connection to the MH-RD sensor
ser = serial.Serial('/dev/ttyUSB0', 9600)

# Read data from the sensor
data = ser.readline()

# Split the data by commas
co2, temp = data.split(',')

# Print the CO2 concentration and temperature
print("CO2 concentration:", co2)
print("Temperature:", temp)

# Close the serial connection
ser.close()