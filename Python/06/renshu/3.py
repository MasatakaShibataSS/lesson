answer = ["京都", "北海道", "沖縄", "博多", "北海道", "大阪",
"京都", "京都","大阪", "京都", "京都", "大阪", "京都",
"京都", "博多", "沖縄","沖縄", "博多", "沖縄", "博多",
"沖縄", "北海道", "北海道", "沖縄", "沖縄", "北海道", "博多",
"北海道", "沖縄", "北海道", "大阪", "北海道", "博多", "博多",
"北海道", "北海道", "北海道","沖縄", "沖縄", "京都"]

# 空の辞書を用意
results = { }

# 辞書resultsに国と得票数を格納する

#    ここにコードを記述してください。
for region in answer:
    if region in results:
        results[region] += 1
    else :
        results[region] = 1
# 結果を表示する
print(results)

for region, num in results.items():

    print(region,":",num)
