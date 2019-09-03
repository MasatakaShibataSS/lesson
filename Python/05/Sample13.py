city = ["東京", "名古屋", "大阪", "京都"]
sale = [80, 60, 22, 50, 75]

print("都市名データは", city, "です。")
print("売上データは", sale, "です。")

print("データを組み合わせます。")

for d in zip(city, sale):
    print(d)

print("データを分解します。")
# cityとsaleを関連付けて融合させた後にcとsに分解している
for c, s in zip(city, sale):
    print("都市名は", c, "売上は", s)
# アンパック
a,b,c,d = city
print(a, end=" ")
print(b, end=" ")
print(c, end=" ")
print(d, end=" ")
