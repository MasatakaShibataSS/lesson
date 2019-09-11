import sys, csv

if len(sys.argv) < 2:
	print("csv ファイルを指定してください")
	print("python3 プログラム.py ファイル.csv")
	sys.exit()

answer = []
try:
    with open(sys.argv[1], "r", encoding="utf_8") as fp:
        reader = csv.reader(fp)
        for csvlst in reader:
            answer += csvlst

except FileNotFoundError:
        print("ファイルが見つかりません")
        sys.exit()

except PermissionError:
        print("ファイルの読み取り許可がありません")
        sys.exit()

# 辞書resultsに地域と数格納する
results = {}
for region in answer:
    if region in results:
        results[region] += 1
    else:
        results[region] = 1

# 結果をソートして表示する
for region in sorted(results.items(), key=lambda c:c[1], reverse=True):
    print("{}: {}".format(region[0], region[1]))
