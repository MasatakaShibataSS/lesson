sale = {"東京":80, "名古屋":60, "京都":22, "大阪":50, "福岡":75}
print("現在のデータは", sale, "です。")

k = input("どのキーのデータを表示しますか？")
if k in sale:
    print(k, "のデータは", sale[k], "です。")
else:
    print(k, "のデータはみつかりませんでした。")
