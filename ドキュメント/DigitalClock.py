mport tkinter as tk
import time as tm

class DigitalClock(tk.Frame):
    def __init__(self, master=None,font_style="Helvetica", font_size=40):
        super().__init__(master)
        self.pack()
        self.buff = tk.StringVar()
        self.buff.set('')
        self.lb = tk.Label(self,textvariable = self.buff, font=(font_style,font_size,'bold'))
        self.lb.pack()
        self.show_time()

    # 時刻の表示
    def show_time(self):
        self.buff.set(tm.strftime('%I:%M:%S'))
        self.after(1000, self.show_time)

if __name__ == "__main__":
    root = tk.Tk()
    root.title("デジタル時計")
    root.geometry("200x100")
    app = DigitalClock(master=root, font_style='FixedSys',font_size=24)
    app.mainloop()
