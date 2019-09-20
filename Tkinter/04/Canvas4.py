import tkinter as tk

root = tk.Tk()
root.title("Canvas")

# 300x200のキャンバスの中心にgif画像ファイルを表示する
c1 = tk.Canvas(width = 300, height = 200)
c1.pack()

image_data = tk.PhotoImage(file ='img_05_l.gif')
id = c1.create_image(150,100, image=image_data)

root.mainloop()
