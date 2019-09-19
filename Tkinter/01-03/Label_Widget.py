import tkinter as tk

root = tk.Tk()
root.title("Label")
root.geometry("200x150")

#Label
lb = tk.Label(root, text="Python Tkinter")
lb.pack()

root.mainloop()
