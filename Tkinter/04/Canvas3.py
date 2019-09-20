import tkinter as tk

root = tk.Tk()
root.title("Canvas")

# 150x150のキャンバスの直線で「N 」を描く
c1 = tk.Canvas(width = 150, height = 150)
id = c1.create_line(10,140,10,10,140,140,140,10,)
c1.pack()

root.mainloop()
