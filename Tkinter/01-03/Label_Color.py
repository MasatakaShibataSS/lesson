import tkinter as tk

root = tk.Tk()
root.title("Label")
root.geometry("200x150")

#Label
lb = tk.Label(text="Python",fg='white',bg='blue')
lb.pack()

root.mainloop()
