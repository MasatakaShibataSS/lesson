import sys

if len(sys.argv) < 2:
    print("ファイル名を指定してください。")
    sys.exit()

f = open(sys.argv[1], "r")

lines = f.readlines()

for line in lines:
    print(line, end="")

f.close()
 
