import PCF8591 as ADC
import RPi.GPIO as GPIO
import time
import math

DO = 17
GPIO.setmode(GPIO.BCM)

def setup():
    ADC.setup(0x48)
    GPIO.setup(DO, GPIO.IN)

def Print(x):
    if x == 1:
        print('''
              ****
              Not raining
              ****''')
    if x == 0:
        print('''
              ****
              Raining!
              ****''')
        
def loop():
    status = 1
    while True:
        print (ADC.read(0))
        
        tmp = GPIO.input(DO)
        if tmp != status:
            Print(tmp)
            status = tmp
        time.sleep(0.2)
        
setup()
loop()
