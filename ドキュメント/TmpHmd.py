import tkinter as tk
import dht11
import RPi.GPIO as GPIO
import time
import datetime

# initialize GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
#GPIO.cleanup()

class TmpHmd(tk.Frame):

    def __init__(self, master=None,font_style="Helvetica", font_size=40):
        self.master = master
        super().__init__(master)
        self.pack()

        self.temp_label = tk.Label(self, text='温度:', font=(font_style, font_size,'bold'))
        self.temp_label.grid(row=0)
        self.hum_label = tk.Label(self, text='湿度:', font=(font_style, font_size,'bold'))
        self.hum_label.grid(row=1)
        self.instance = dht11.DHT11(pin=17)
        self.update_reading()

    def update_reading(self):

        result = self.instance.read()
        if result.is_valid():
            print("Last valid input: " + str(datetime.datetime.now()))
            print("Temperature: %d C" % result.temperature)
            print("Humidity: %d %%" % result.humidity)

            reading_str = "温度: {:.0f}℃".format(result.temperature)
            self.temp_label.configure(text=reading_str)

            reading_str = "湿度: {:.0f}％".format(result.humidity)
            self.hum_label.configure(text=reading_str)



        self.master.after(3000, self.update_reading)

if __name__ == '__main__':
    root = tk.Tk()
    root.wm_title('Temp Humidity')
    app = TmpHmd(root, font_style='FixedSys',font_size=24)
    root.geometry("300x200+730+360")
    app.mainloop()
