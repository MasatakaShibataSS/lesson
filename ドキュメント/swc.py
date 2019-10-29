#! /user/bin/env python

import RPi.GPIO as GPIO
import time


GPIO.setmode(GPIO.BCM)
GPIO.setup(9, GPIO.IN, pull_up_down=GPIO.PUD_UP)

count = 0

while True:
    if(GPIO.input(9) == 0):

        count = count + 1
        print ("Count:" + str(count))
        while (GPIO.input(9) == 0):

            TIME.SLEEP(0.1)
