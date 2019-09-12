str = ["Sample.csv", "Sample.exe", 
       "Sample1.py", "Sample2.py",
       "Sample.txt","index.html"
      ]
file = []

print("ファイルのリストは以下です。")

for s in str:
    print(s)

suf = input("拡張子を入力してください。")

for s in str:
    res = s.endswith(suf)
    if res is True:
        file.append(s)

print("該当するファイルのリストは以下です。")

for f in file:
    print(f)
