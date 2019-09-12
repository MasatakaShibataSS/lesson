import csv

f = open("Sample.csv", "r")

rd = csv.reader(f)

for row in rd:
    for col in row:
       print(col, end=",")
    print()
f.close()
