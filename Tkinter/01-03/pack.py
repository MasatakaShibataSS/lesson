import tkinter as tk

root = tk.Tk()
root.title("packer")
root.geometry("200x150")
color = ('red', 'blue', 'green', 'yellow')

# ラベルの作成
for x in range(4):
    label = tk.Label(root, text = "label{}". format(x), background = color[x])
    label.pack()

root.mainloop()
