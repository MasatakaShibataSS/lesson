num = int(input("何月の処理を飛ばしますか？(1～12)"))

for i in range(12):
    if (i+1) == num:
        continue
    print(i+1 , "月のデータです。")
