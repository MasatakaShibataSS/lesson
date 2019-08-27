data1 = [1,2,3,4,5]
data2 = list(data1)
# data2 = data1.copy()


print("data1は", data1, "です。")
print("data2は", data2, "です。")

data1[0] = 10

print("data1を変更します。")

print("data1は", data1, "です。")
print("data2は", data2, "です。")
