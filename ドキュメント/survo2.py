import tkinter as tk
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)
pwm = GPIO.PWM(18,50)
pwm.start(2.5)

class App:

    def __init__(self, master):
        self.v = tk.IntVar()
        self.v.set(0)

        self.frame = tk.Frame(master)
        self.frame.pack()
        # Radioボタンの生成と配置
        self.right =tk.Radiobutton(self.frame,text='RIGHT ',variable=self.v, value = 1,
　　　　　　　　　　　　　　　　 command=self.change_state)
        self.right.pack()
        self.cent =tk.Radiobutton(self.frame,text='CENTER',variable=self.v, value = 2,
　　　　　　　　　　　 　　　　　command=self.change_state)
        self.cent.pack()
        self.left =tk.Radiobutton(self.frame,text='LEFT  ',variable=self.v, value = 3,
　　　　　　　　　　　　　　　　command=self.change_state)
        self.left.pack()

    def change_state(self):
        btn = self.v.get()
        # LEFT
        if btn == 1:
            duty = float(2.5)
            pwm.ChangeDutyCycle(duty)
        # CENTER
        elif btn == 2:
            duty = float(90/20.0 + 2.5)
            pwm.ChangeDutyCycle(duty)
        # RIGHT
        elif btn == 3:
            duty = float(180/20.0 + 2.5)
            pwm.ChangeDutyCycle(duty)
        else:
            print('Error')

if __name__ == '__main__':
    root = tk.Tk()
    root.wm_title('Servo Control')
    app = App(root)
    root.geometry("200x150")
    root.mainloop()
    GPIO.cleanup()

 
