f = open("Sample.txt","r")

lines = f.readlines()

for line in lines:
    # print(line, end="")
    print(line)


f.close()
