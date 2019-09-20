import tkinter as tk

root = tk.Tk()
root.title("Canvas")

# 150x150のキャンバスのx0=10,y0=10,x1=140,y1=140の矩形領域に円を描く
c1 = tk.Canvas(width = 150, height = 150)
id = c1.create_oval(10,10,140,140)
c1.pack()

root.mainloop()
