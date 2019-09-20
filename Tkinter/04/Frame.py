import tkinter as tk

root = tk.Tk()
root.title('Frame')

#フレーム生成
frame0 = tk.Frame(root)
frame1 = tk.Frame(root)

#frame0にラベルとボタンの配置/ウィジェット生成時にframeに配置
tk.Label(frame0, text ='ボタンを押してください').pack()
tk.Button(frame0, text ='Button#1').pack(side = 'left')
tk.Button(frame0, text ='Button#2').pack(side = 'left')
tk.Button(frame0, text ='Button#3').pack(side = 'left')

#frame1にボタンの配置/ジオメトリマネージャでframeに配置
tk.Button(text ='Button#4').pack(in_ = frame1, fill = 'both')
tk.Button(text ='Button#5').pack(in_ = frame1, fill = 'both')
tk.Button(text ='Button#6').pack(in_ = frame1, fill = 'both')

#フレームの配置
frame0.pack()
frame1.pack(fill = 'both')

root.mainloop()
