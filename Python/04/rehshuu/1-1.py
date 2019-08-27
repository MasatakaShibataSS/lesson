month = int(input("月の数値(1～12)を入力してください: "))

if(month == 12) or (month == 1) or (month == 2):

    print("冬")

elif (month >= 3) and (month <= 5):

    print("春")

elif (month >= 6) and (month <= 8 ):

    print("夏")

elif (month <= 9 ) and (month < 11):

    print("秋")

else:

    print("1～12の数値を入力してください。")
