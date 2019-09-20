import tkinter as tk

root = tk.Tk()
root.title("Checkbutton機能")
root.geometry("200x150")

# ラベル表示文字
on_off = {True:"ON",False:"OFF"}

# Labelオブジェクトの生成と配置
lb = tk.Label(root, text= on_off[False])
lb.pack()

# Checkbuttonのvariableのset(),get()定義
chk = tk.BooleanVar()
chk.set(False)

# Checkbuttonのイベントハンドラー関数
def checked():
    lb.configure(text = on_off[chk.get()])

# Checkbuttonの生成と配置
check_btn = tk.Checkbutton(variable = chk, text='Check', command=checked)
check_btn.pack()

root.mainloop()
 
