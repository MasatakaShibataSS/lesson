sale = int(input("売上を入力してください。"))
num = int(input("人数を入力してください。"))

if sale >= 100 and num >= 30 :
    print("売上は大盛況です。")
elif sale >= 100:
    print("売上は好調です。")
elif sale >= 50:
    print("売上は普通です。")
else:
    print("売上は低調です。")

print("処理を終了します。")
