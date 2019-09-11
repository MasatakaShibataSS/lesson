import csv

fp = open("./answer.csv", "r", encoding="utf_8")
reader = csv.reader(fp)


answer = []
for csvlst in reader:
    answer += csvlst

# 空の辞書を用意
results = { }


# 辞書resultsに地域と数格納する
for region in answer:
    if region in results:
        results[region] += 1
    else:
        results[region] = 1

# 結果をソートして表示する
for region in sorted(results.items(), key=lambda c:c[1], reverse=True):

    print(region[0],":",region[1])
