import os
import os.path

curdir = os.listdir(".")

print("名前", end="\t")
print("サイズ")

for name in curdir:
    print(name, end="\t")
    print(os.path.getsize(name), "バイト")
