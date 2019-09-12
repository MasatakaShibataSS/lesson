data = [1, 2, 3, 4, 5]
print("現在のデータは", data, "です。")

print("data[::-1]をfor文で処理します。")
for d in data[::-1]:
    print(d)
print("data[::-1]は", data[::-1], "です。")
print("現在のデータは", data, "です。")

print("reversed(data)をfor文で処理します。")
for d in reversed(data):
    print(d)
print("reversed(data)は", reversed(data), "です。")
print("現在のデータは", data, "です。")

print("data.reverse()を処理します。")
data.reverse()
print("現在のデータは", data, "です。")
