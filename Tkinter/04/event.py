import tkinter as tk

root = tk.Tk()
root.title("Buttun機能")
root.geometry("200x150")

def button_on(event):
    label_str.set("on")

def button_off(event):
    label_str.set("off")

label_str = tk.StringVar()
label_str.set('NON')

tk.Label(textvariable = label_str).pack()

Btn_on = tk.Button(text="ON", width=3)
Btn_on.bind("<Button-1>", button_on)
Btn_on.pack()

Btn_off = tk.Button(text="OFF", width=3)
Btn_off.bind("<Button-1>", button_off)
Btn_off.pack()


root.mainloop()
