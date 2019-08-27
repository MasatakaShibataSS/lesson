num = int(input("2以上の整数を入力してください: "))

for i in range(2,num+1):

    if(i == num):

        print(num,"は素数です。")

    elif(num % i == 0):

        print(num,"は素数ではありません。")

        break
