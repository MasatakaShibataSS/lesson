n = int(input("Input number: "))

print("----+----+----")

for i in range(n):

     i+=1

     print(" "*(n-i) ,end="")

     print("* " * i)
