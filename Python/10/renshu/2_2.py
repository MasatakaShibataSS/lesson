import sys

if len(sys.argv) < 2:
    print("ファイル名を指定してください。")
    sys.exit()

f = open(sys.argv[1], "r")

lines = f.readlines()

for line in lines:
    print(line, end="")

f.close()


try:
    f = open("answer.csv", "r")

except FileNotFoundError:
    print("ファイルが見つかりませんでした。")

else:
    lines = f.readlines()
    for line in lines:
        print(line, end="")
    f.close()

finally:
    print("処理を終了します。")
