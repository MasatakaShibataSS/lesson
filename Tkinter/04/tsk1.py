import tkinter as tk

root = tk.Tk()
root.title("entry")
root.geometry("200x150")


def button_on():
	value = EditBox.get()
	Lb.configure(text=value)


Lb = tk.Label(text = "NON",width = 20)
Lb.pack()


# entry

EditBox = tk.Entry()
EditBox.insert(tk.END, "名前の入力")
EditBox.pack()


Btn_on = tk.Button(text="OK", width=3, command=button_on)
Btn_on.pack()


root.mainloop()

# root.mainloop()をコメントアウトしてpython -i プログラム名でインタラクティブモードで返ってくる
# EditBox.delete(0, tk.END)  デリート
# EditBox.insert(tk.END, "hello")　インサート
# EditBox.get()　取得
