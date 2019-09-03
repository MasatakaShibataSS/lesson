# スライス [開始:終了:間隔]
ysale = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
print("年間のデータは", ysale, "です。")

sale1 = ysale[:6]
print("上半期のデータは", sale1, "です。")

sale2 = ysale[6:]
print("下半期のデータは", sale2, "です。")

sale3 = ysale[::2]
print("一ヶ月おきのデータは", sale3, "です。")

sale4 = ysale[::-1]
print("逆順のデータは", sale4, "です。")

print("年間のデータは", ysale, "です。")
print("上半期のデータを差し替えます。")



n1 = int(input("１つめの要素は?"))
n2 = int(input("2つめの要素は?"))
n3 = int(input("3つめの要素は?"))
sale6 = ysale[n1:n2:n3]
print("1つ目は",n1)
print("2つ目は",n2)
print("3つ目は",n3)

print("データは", sale6, "です。")
