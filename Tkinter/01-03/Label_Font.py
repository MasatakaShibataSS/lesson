import tkinter as tk

root = tk.Tk()
root.title("Label")
root.geometry("200x150")

#Label
lb = tk.Label(text="Python",font=('FlexSys','19','bold'))
lb.pack()

root.mainloop()
