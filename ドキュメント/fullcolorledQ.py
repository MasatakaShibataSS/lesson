#! /usr/bin/env /usr/bin/python
# _*_ coding: utf-8 _*_

import RPi.GPIO as GPIO
import time

#GPIO.cleanup()

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)    # Red
GPIO.setup(23, GPIO.OUT)    # Blue
GPIO.setup(24, GPIO.OUT)    # Green

pwmRed = GPIO.PWM(18,500)
pwmRed.start(0)

pwmBlue =GPIO.PWM(23,500)
pwmBlue.start(0)

pwmGreen = GPIO.PWM(24,500)
pwmGreen.start(0)

def light_led(r,g,b):
    pwmRed.ChangeDutyCycle(r)
    pwmBlue.ChangeDutyCycle(b)
    pwmGreen.ChangeDutyCycle(g)

while True:
#   青⇒紫⇒赤
    r=0;b=100;g=0
    for r in range(100):
        light_led(r,g,b)
        print(r,g,b)
        b -=1
        time.sleep(0.5)
# 赤⇒黄⇒緑
    r = 100
    for g in range(100):
        light_led(r,g,b)
        print(r,g,b)
        r -=1
        time.sleep(0.5)
# 緑⇒青
    g = 100
    for b in range(100):
        light_led(r,g,b)
        print(r,g,b)
        g -= 1
        time.sleep(0.5)
