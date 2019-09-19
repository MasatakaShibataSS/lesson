import tkinter as tk

root = tk.Tk()
root.title("gridder")
root.geometry("200x150")
color = ('red', 'blue', 'green', 'yellow')

#ラベルの作成
label1 =tk.Label(root, text = "Label 1", background = color[0])
label2 =tk.Label(root, text = "Label 2", background = color[1])
label3 =tk.Label(root, text = "Label 3", background = color[2])
label4 =tk.Label(root, text = "Label 4", background = color[3])

label1.grid(column=0,row=0)
label2.grid(column=1,row=0)
label3.grid(column=0,row=1)
label4.grid(column=1,row=1)

root.mainloop()
