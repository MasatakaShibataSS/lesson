import tkinter as tk

root = tk.Tk()
root.title("Canvas")

# 150x150のキャンバスのx0=10,y0=10,x1=140,y1=140にの矩形を描く
c1 = tk.Canvas(width = 150, height = 150)
id = c1.create_rectangle(10,10,140,140, fill='yellow')
c1.pack()

root.mainloop()
