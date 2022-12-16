#!/usr/ bin/python
# coding=utf-8

import time
import board
import busio
import adafruit_ads1x15.ads1115 as ADS
from adafruit_ads1x15.analog_in import AnalogIn
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
LED_Pin = 17
GPIO.setup(LED_Pin, GPIO.OUT)
# create i2c
i2c = busio.I2C(board.SCL, board.SDA)
ads = ADS.ADS1115(i2c)

# single ended input on channels
chan0 = AnalogIn(ads, ADS.P0)
chan1 = AnalogIn(ads, ADS.P1)
chan2 = AnalogIn(ads, ADS.P2)
chan3 = AnalogIn(ads, ADS.P3)

while True:
    # print("channel 0:" ", "{:>5}\t{:>5.3f}".format(chan0.value, chan0.voltage))
    # chan1 , 2,3
    # time.sleep(1)

    GPIO.output(LED_Pin, False)
    time.sleep(0.000280)
    dustVal = chan0.value
    time.sleep(0.00040)
    GPIO.output(LED_Pin, True)
    time.sleep(0.009680)

    time.sleep(1)
    if (dustVal > 36.455):
        print((dustVal / 1024) - 0.0356) * 120000 * 0.035)
