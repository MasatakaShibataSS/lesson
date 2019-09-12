city = {"東京", "名古屋", "京都", "大阪", "福岡"}
print("現在のデータは", city, "です。")

d = input("追加するデータを入力してください。")
if d in city:
    print(d, "はすでに存在しています。")
else:
    city.add(d)
    print(d, "を追加しました。")
print("現在のデータは", city, "です。")

d = input("削除するデータを入力してください。")
if d in city:
    city.remove(d)
    print(d, "を削除しました。")
else:
    print(d, "はみつかりませんでした。")
print("現在のデータは", city, "です。")
