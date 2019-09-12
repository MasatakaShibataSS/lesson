sale = {"東京":80, "名古屋":60, "京都":22, "大阪":50, "福岡":75}
print("現在のデータは", sale, "です。")

k = input("追加するキーを入力してください。")
if k in sale:
    print(k, "のデータはすでに存在しています。")
else:
    d = int(input("追加するデータを入力してください。"))
    sale[k] = d
    print(k, "のデータとして", sale[k], "を追加しました。")
print("現在のデータは", sale, "です。")

k = input("どのキーのデータを変更しますか？")
if k in sale:
    print(k, "のデータは", sale[k], "です。")
    d = int(input("データを入力してください。"))
    sale[k] = d
    print(k, "のデータは", sale[k], "に変更されました。")
else:
    print(k, "のデータはみつかりませんでした。")
print("現在のデータは", sale, "です。")

k = input("どのキーのデータを削除しますか？")
if k in sale:
    print(k, "のデータは", sale[k], "です。")
    del sale[k]
    print("データを削除しました。")
else:
    print(k, "のデータはみつかりませんでした。")
print("現在のデータは", sale, "です。")
