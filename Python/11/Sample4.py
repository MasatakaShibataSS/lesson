import csv

f = open("Sample2.csv","w")

w = csv.writer(f)
# w.writerow(["東京","消しゴム"])
w.writerows([["東京","定規"],["名古屋","ノート"]])

f.close()
