import RPi.GPIO as GPIO
import time

#GPIO.cleanup()

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)    # Red
GPIO.setup(23, GPIO.OUT)    # Blue
GPIO.setup(24, GPIO.OUT)    # Green

while True:
#   Red ON/OFF
    GPIO.output(18, GPIO.HIGH)
    time.sleep(1)

    GPIO.output(18, GPIO.LOW)
    time.sleep(1)

#   Blue ON/OFF
    GPIO.output(23, GPIO.HIGH)
    time.sleep(1)

    GPIO.output(23, GPIO.LOW)
    time.sleep(1)

#   Green ON/OFF
    GPIO.output(24, GPIO.HIGH)
    time.sleep(1)

    GPIO.output(24, GPIO.LOW)
    time.sleep(1)
