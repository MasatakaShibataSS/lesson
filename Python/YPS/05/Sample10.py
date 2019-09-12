ysale = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
print("年間のデータは", ysale, "です。")

sale1 = ysale[0:6]
print("上半期のデータは", sale1, "です。")

sale2 = ysale[6:]
print("下半期のデータは", sale2, "です。")

sale3 = ysale[::2]
print("一か月おきのデータは", sale3, "です。")

sale4 = ysale[::-1]
print("逆順のデータは", sale4, "です。")

print("年間のデータは", ysale, "です。")
print("上半期のデータを差し替えます。")
ysale[:6] = [0, 0, 0, 0, 0, 0]
print("年間のデータは", ysale, "です。")
