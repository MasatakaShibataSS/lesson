data = [
   ["東京", 32, 25], 
   ["名古屋", 28, 21], 
   ["大阪", 27, 20],
   ["京都", 26, 19],
   ["福岡", 27, 22]
]

print("現在のデータは", data, "です。")

for dat in data:
   print("都市別データは", dat, "です。")
   for d in dat:
      print(d, end="\t")
   print()
   
print(data[0][0], "の最高気温は", data[0][1], "最低気温は", data[0][2], "です。")
