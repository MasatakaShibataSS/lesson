city = ["東京", "名古屋", "大阪", "京都"]
sale = [80, 60, 22, 50, 75]

print("都市名データは", city, "です。")
print("売上データは", sale, "です。")

print("データを組み合わせます。")

for d in zip(city, sale):
    print(d)

print("データを分解します。")

for c, s in zip(city, sale):
    print("都市名は", c, "売上は", s)

