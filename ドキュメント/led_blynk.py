#! /user/bin/env python
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(4, GPIO.OUT)

try:
    while True:
        #GPIO.output(4, GPIO.HIGH)
        #GPIO.output(4, 1)
        GPIO.output(4, True)
        time.sleep(1)
        
        #GPIO.output(4, GPIO.LOW)
        #GPIO.output(4, 0)
        GPIO.output(4, False)
        time.sleep(1)

except:
    GPIO.cleanup()
