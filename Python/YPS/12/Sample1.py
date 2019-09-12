import statistics

data = [8, 17, 0, 11, 6, 21, 16, 6, 17, 11, 
        7, 9, 6, 13, 12, 16, 3, 14, 13, 12]

print("平均値は", statistics.mean(data), "です。")
print("中央値は", statistics.median(data), "です。")
print("最頻値は", statistics.mode(data), "です。")
print("分散は", statistics.pvariance(data), "です。")
print("標準偏差は", statistics.pstdev(data), "です。")
