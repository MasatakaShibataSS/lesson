import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

GPIO.setup((23,18,15,24,25,7,8,14),GPIO.OUT)
GPIO.output((23,18,15,24,25,7,8,14),GPIO.LOW)

ssg = {'A':23, 'B':18, 'C':15, 'D',:24, 'E':25, 'F':7, 'G':8, 'DP':14}

GPIO.output(ssg['A'], 1)

GPIO.cleanup()
