import tkinter as tk

root = tk.Tk()
root.title("Canvas")

# 150x150のキャンバスに文字を描きます。
c1 = tk.Canvas(width = 150, height = 150)
id = c1.create_text(75,75,text= 'Hello Python', font=('FixedSys', 14))
c1.pack()

root.mainloop()
