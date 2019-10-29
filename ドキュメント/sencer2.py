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
        #ここに距離計測処理を記述します。
        return (distance_cm, distance_in)

    def update_reading(self):
        cm, inch = self.get_distance()
        self.dist_str.set("{:.2f}".format(cm))
        self.master.after(500, self.update_reading)


root = tk.Tk()
root.wm_title('Range Finder')
app = App(root)
root.geometry("450x350+730+360")
root.mainloop()
