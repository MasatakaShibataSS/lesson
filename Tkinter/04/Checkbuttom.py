import tkinter as tk

root = tk.Tk()
root.title("Checkbutton機能")
root.geometry("200x150")

# Checkbutton
chk = tk.BooleanVar()
chk.set(False)

def checked():
    print("variable:", chk.get())

check_btn = tk.Checkbutton(variable = chk, text='Check', command=checked)
check_btn.pack()

root.mainloop()
