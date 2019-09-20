import tkinter as tk

root = tk.Tk()
root.title("Raidobutton機能")
root.geometry("200x150")

# 選択されたラジオボタン以外を無効にする
def change_state():
    btn = v.get()

    if btn == 1:
        radio2.configure(state = "disabled")
        radio3.configure(state = "disabled")

    elif btn == 2:
        radio1.configure(state = "disabled")
        radio3.configure(state = "disabled")

    elif btn == 3:
        radio1.configure(state = "disabled")
        radio2.configure(state = "disabled")

    elif btn == 0:
        pass

    else:
        print("Error",btn)

v = tk.IntVar()
v.set(0)

# ラジオボタン・オブジェクトの生成と配置
radio1 = tk.Radiobutton(text="選択項目#1", variable = v, value = 1, command = change_state)
radio1.pack()

radio2 = tk.Radiobutton(text="選択項目#2", variable = v, value = 2, command = change_state)
radio2.pack()

radio3 = tk.Radiobutton(text="選択項目#3", variable = v, value = 3, command = change_state)
radio3.pack()

root.mainloop()
 
