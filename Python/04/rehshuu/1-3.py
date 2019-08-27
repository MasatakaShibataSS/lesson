year = int(input("西暦の年を入力してください。: "))

if((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0):

    print(year,"年はうるう年です。")

else:

    print(year, "年はうるう年ではありません。")
