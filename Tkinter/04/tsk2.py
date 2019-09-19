import tkinter as tk

root = tk.Tk()
root.title("Entry")
root.geometry("200x150")

def button_on(event):
    label_str.set(EditBox.get())
    # EditBox.delete(0,tk.END)

def button_clear(event):
    EditBox.delete(0, tk.END)


label_str = tk.StringVar()
tk.Label(textvariable = label_str).pack()

#Entry
EditBox = tk.Entry(width = 20)
EditBox.insert(tk.END, "名前の入力")
EditBox.pack()

Btn_on = tk.Button(text="OK",width=3)
Btn_on.bind("<Button-1>", button_on)
Btn_on.bind("<Button-3>", button_clear)

Btn_on.pack()

root.mainloop()
