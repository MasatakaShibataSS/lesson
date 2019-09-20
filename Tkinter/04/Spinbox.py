import tkinter as tk

root = tk.Tk()
root.title('Spinbox機能')
root.geometry("200x150")
root.option_add('*font', ('FixeSys',14))

month = ("January","February", "March", "April")

#spinboxの生成と配置
sp1 = tk.Spinbox(value = month, width = 20, state = 'readonly')
sp2 = tk.Spinbox(from_ =1, to = 31, increment =1, width = 20)
sp3 = tk.Spinbox(from_ = 1, to = 5, increment = 0.5, format = '%05.2f', width = 20)

for w in (sp1, sp2, sp3):
    w.pack(padx = 5, pady = 5, fill = 'both')

#OKボタンの生成、配置、イベント関数
def clicked():
    print(sp1.get())
    print(sp2.get())
    print(sp3.get())

btn = tk.Button(text = 'OK', command = clicked)
btn.pack()

root.mainloop()
