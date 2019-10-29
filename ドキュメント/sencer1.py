import RPi.GPIO as GPIO
import time

trigger_pin = 18
echo_pin = 23

GPIO.setmode(GPIO.BCM)
GPIO.setup(trigger_pin, GPIO.OUT)
GPIO.setup(echo_pin, GPIO.IN)

def send_trigger_pulse():
    GPIO.output(trigger_pin, True)
    time.sleep(0.0001)
    GPIO.output(trigger_pin, False)

def wait_for_echo(value, timeout):
    count = timeout
    while GPIO.input(echo_pin) != value and count > 0:
        count = count - 1

def get_distance():
    send_trigger_pulse()                 # トリガー出力(実測:200μ秒パルス出力)
    wait_for_echo(True, 10000)           # エコーがHIGHになるのを待つ(実測:80m秒でtimeout)
    start = time.time()                  # タイマースタート
    wait_for_echo(False, 10000)          # エコーがLOWになるのを待つ
    finish = time.time()                 # タイマーストップ
    pulse_len = finish - start           # エコー時間を計算
    distance_cm = pulse_len * 340.29 / 2 * 100    # 音速(340.29m/s)/往復 * 100cm
#    distance_cm = pulse_len / 0.000058
    distance_in = distance_cm / 2.5
    return (distance_cm, distance_in)


while True:
#    print("cm=%f\tinches=%f" % get_distance())
#    cm, inches = get_distance()
#    print("cm={:.2f} inhches={:.2f}".format(cm, inches))
    print("cm={:.2f} inhches={:.2f}".format(*get_distance()))
    time.sleep(1)
