city = ["東京", "名古屋", "大阪", "京都"]
sale = [80, 60, 22, 50, 75]

print("都市名データは", city, "です。")
print("売上データは", sale, "です。")

print("データを組み合わせます。")

for d in zip(city, sale):
    print(d)

print("データとインデックスを組み合わせます。")

for d in enumerate(city):
    print(d)
