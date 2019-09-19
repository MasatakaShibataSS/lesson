import tkinter as tk

root = tk.Tk()
root.title("entry")
root.geometry("200x150")

# entry

EditBox = tk.Entry()
EditBox.insert(tk.END, "名前の入力")
EditBox.pack()

# root.mainloop()

# root.mainloop()をコメントアウトしてpython -i プログラム名でインタラクティブモードで返ってくる
# EditBox.delete(0, tk.END)  デリート
# EditBox.insert(tk.END, "hello")　インサート
# EditBox.get()　取得
