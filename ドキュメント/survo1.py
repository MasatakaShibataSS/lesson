import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)
pwm = GPIO.PWM(18,50)
pwm.start(2.5)

while(True):
    for angle in range(181):
        duty = float(angle)/20.0 +2.5
        pwm.ChangeDutyCycle(duty)
        print(duty)
        time.sleep(0.1)
