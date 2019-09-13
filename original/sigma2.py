
def sigma(i, m, c):
    ni = 0
    ma = m + 1
    for i in range(i,ma):
        ni += c
    return ni

i = int(input("iの開始値を入力してください"))
m = int(input("最大値を入力してください"))
c = int(input("iを含めた計算式を入力してください"))
print(sigma(i, m, c))
