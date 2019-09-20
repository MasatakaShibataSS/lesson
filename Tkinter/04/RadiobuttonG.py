import tkinter as tk

root = tk.Tk()
root.title("Raidobutton機能")
root.geometry("200x150")

# 選択されたラジオボタン以外を無効にする
def state1():
    btn = v1.get()

    if btn == 1:
        radio12.configure(state = "disabled")

    elif btn == 2:
        radio11.configure(state = "disabled")

    elif btn == 0:
        pass

    else:
        print("Error",btn)

def state2():
    btn = v2.get()
    if btn == 1:
        radio22.configure(state = "disabled")

    elif btn == 2:
        radio21.configure(state = "disabled")

    elif btn == 0:
        pass

    else:
        print("Error",btn)

# 選択ボタンのリセット
def reset():
    radio11.configure(state = "normal")
    radio12.configure(state = "normal")
    radio21.configure(state = "normal")
    radio22.configure(state = "normal")
    v1.set(0)
    v2.set(0)

v1 = tk.IntVar()
v1.set(0)
v2 = tk.IntVar()
v2.set(0)
# Frameの生成と配置
frame1 = tk.LabelFrame(root, text = "Group1")
frame1.pack()
# ラジオボタン・オブジェクトの生成と配置
radio11 = tk.Radiobutton(frame1, text ="選択項目#1", variable=v1, value=1, command=state1)
radio11.pack()

radio12 = tk.Radiobutton(frame1, text ="選択項目#2", variable=v1, value=2, command=state1)
radio12.pack()

# Frameの生成と配置
frame2 = tk.LabelFrame(root ,text= "Group2")
frame2.pack()
# ラジオボタン・オブジェクトの生成と配置
radio21 = tk.Radiobutton(frame2, text ="選択項目#1", variable=v2, value=1, command=state2)
radio21.pack()

radio22 = tk.Radiobutton(frame2, text ="選択項目#2", variable=v2, value=2, command=state2)
radio22.pack()

# RESETボタンの生成と配置
restbtn = tk.Button(text="RESET", command = reset)
restbtn.pack()

root.mainloop()
