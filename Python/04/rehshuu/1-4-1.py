m = int(input("Input number: "))

print("----+----+----")

n = m-1

for i in range(n):

    for j in range(n-i):

        print(" ", end="")

    for k in range(n-j):

        print("* ", end="")

    print()

print("* "* m)
 
