sale = {"東京":80, "名古屋":60, "京都":22, "大阪":50, "福岡":75}
print("現在のデータは", sale, "です。")
sale["仙台"]=50
print("仙台を追加したデータは", sale, "です。")
k = input("どの支店のデータを表示しますか？")
if k in sale:
    print(k, "のデータは", sale[k], "です。")
else:
    print(k, "のデータは見つかりませんでした。")

# 有る無しをTure Falus で返してくる
# "東京" in sale
# "北海道" not in sale
