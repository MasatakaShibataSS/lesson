num = int(input("何月の処理で終了しますか？(1～12)"))

for i in range(12):
    print(i+1 , "月のデータです。")
    if (i+1) == num:
        break
