import RPi.GPIO as GPIO
import sys
import time
from pitches import pitches

buzzer_pin = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer_pin, GPIO.OUT)
pwmBuzz = GPIO.PWM(buzzer_pin, 440)

def tonebuzz(duration,melody,noteDurations):
    if duration == 0:
        duration = 1
    n = 0
    pwmBuzz.start(0)
    for m in melody:
        if m != "0":
            pwmBuzz.ChangeFrequency(pitches[m])
            pwmBuzz.ChangeDutyCycle(50.0)
        noteDuration =duration/noteDurations[n]
        time.sleep(noteDuration)
        n += 1
        pwmBuzz.ChangeDutyCycle(0)
        time.sleep(noteDuration * 1.0)
    pwmBuzz.stop()

if __name__ == "__main__":

    melody = ["NOTE_C4", "NOTE_G3", "NOTE_G3", "NOTE_A3", "NOTE_G3", "0", "NOTE_B3", "NOTE_C4"]
    noteDurations = [4,8,8,4,4,4,4,4]

    while True:
        duration_s = input("Enter Duration (seconds): ")
        duration = float(duration_s)
        if duration == 0:
            GPIO.cleanup()
            sys.exit()
        tonebuzz(duration,melody, noteDurations) 
