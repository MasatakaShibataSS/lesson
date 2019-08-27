data1 = [1,2,3,4,5]
data2 = data1

print("data1は", data1, "です。")
print("data2は", data2, "です。")

data1[0] = 10

print("data1を変更します。")

print("data1は", data1, "です。")
print("data2は", data2, "です。")
print(id(data1))
print(id(data2))
print("deta3を作成しました。")
data3 = [10, 2, 3, 4, 5]
print(id(data3))
print(data1 is data2)
print(data1 is data3)
print(data1 == data2)
print(data1 == data2)
