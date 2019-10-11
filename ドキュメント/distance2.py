import tkinter as tk
import RPi.GPIO as GPIO
import time

trigger_pin = 18
echo_pin = 23

GPIO.setmode(GPIO.BCM)
GPIO.setup(trigger_pin, GPIO.OUT)
GPIO.setup(echo_pin, GPIO.IN)

class App:

    def __init__(self, master):
        self.master = master
        frame = tk.Frame(master)
        frame.pack()
        self.dist_str = tk.StringVar()
        self.dist_str.set('12.34')
        label = tk.Label(frame, text='Distance (cm)', font=("Helvetica", 32))
        label.grid(row=0)
        self.reading_label = tk.Label(frame, textvariable=self.dist_str, font=("Helvetica", 110))

        self.reading_label.grid(row=1)
        self.update_reading()


    def send_trigger_pulse(self):
        GPIO.output(trigger_pin, True)
        time.sleep(0.0001)
        GPIO.output(trigger_pin, False)

    def wait_for_echo(self, value, timeout):
        count = timeout
        while GPIO.input(echo_pin) != value and count > 0:
            count = count - 1

    def get_distance(self):
        self.send_trigger_pulse()          # トリガー出力(実測:200μ秒パルス出力)
        self.wait_for_echo(True, 10000)    # エコーがHIGHになるのを待つ(実測:80m秒でtimeout)
        start = time.time()                # タイマースタート
        self.wait_for_echo(False, 10000)   # エコーがLOWになるのを待つ
        finish = time.time()               # タイマーストップ
        pulse_len = finish - start         # エコー時間を計算
        distance_cm = pulse_len * 340.29 / 2 * 100    # 音速(340.29m/s)/往復 * 100cm
    #    distance_cm = pulse_len / 0.000058
        distance_in = distance_cm / 2.5
        return (distance_cm, distance_in)

    def update_reading(self):
        cm, inch = self.get_distance()
        self.dist_str.set("{:.2f}".format(cm))
        if cm <= 25.5:
#            color = '#%02x%02x%02x' % (255-cm*10, 0,cm*10 )
            color = "#{:02x}{:02x}{:02x}".format(int(255-cm*10),0,int(cm*10))
            self.reading_label.configure(fg=color)
        else:
            self.reading_label.configure(fg='blue')

        self.master.after(500, self.update_reading)

root = tk.Tk()
root.wm_title('Range Finder')
app = App(root)
root.geometry("450x350+730+360")
root.mainloop()
