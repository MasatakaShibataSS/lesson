#! /user/bin/env python

import RPi.GPIO as GPIO
import time

#GPIO.cleanup()

GPIO.setmode(GPIO.BCM)
GPIO.setup(9, GPIO.IN, pull_up_down=GPIO.PUD_UP)

try:
    while True:
        print(GPIO.input(9))
        time.sleep(0.5)

except KeyboardInterrupt:
    GPIO.cleanup()
