city = ["東京", "名古屋", "大阪", "京都"]
sale = [80, 60, 22, 50, 75]

print("都市名データは", city, "です。")
print("売上データは", sale, "です。")

print("データを組み合わせます。")

# for d in enumerate(zip(city, sale)):
for d in zip(city, sale):

    print(d)
#     print("支店:", d[0], "売上:", d[1])
    # print(d[0],d[1][0],d[1][1])

print("データとインデックスを組み合わせます。")
# enumerateはforループの中でリスト（配列）などのイテラブルオブジェクトの要素と同時に
# インデックス番号（カウント、順番）を取得できる

for d in enumerate(sale):
    print(d)

for c in enumerate(city):
    print(c)
