def rpstr(num, str="*"):
    print(str * num)

s = input("文字列を入力してください。")
n = int(input("個数を入力してください。"))

print("文字列あり---")
rpstr(n, s)

print("文字列なし---")
rpstr(n)
