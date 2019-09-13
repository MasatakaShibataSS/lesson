
def sigma(i, m):
    ni = 0
    ma = m + 1
    for i in range(i,ma):
        ni += i
    return ni

i = int(input("∑の計算をおこいます。\niの開始値を入力してください。\n"))
m = int(input("iの最大値を入力してください。\n"))
print(sigma(i, m))
