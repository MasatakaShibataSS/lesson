import tkinter as tk

root = tk.Tk()
root.title("place")
root.geometry("200x150")
color = ('red', 'blue', 'green','yellow')

for x in range(4):
    lab =tk.Label(root, text = "Label {}". format(x+1), bg = color[x])
    lab.place( x=50*x, y=40*x)

root.mainloop()
