import tkinter as tk
import time as tm

root = tk.Tk()
root.title("デジタル時計")
root.geometry("200x100")

buff = tk.StringVar()
buff.set('')

tk.Label(textvariable = buff, font=('FixedSys',14,'bold')).pack()

# 時刻の表示
def show_time():
    buff.set(tm.strftime('%I:%M:%S'))
    root.after(1000, show_time)

show_time()
root.mainloop()
