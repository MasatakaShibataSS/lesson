import sqlite3

conn = sqlite3.connect("pdb.db")

c = conn.cursor()

itr = c.execute("SELECT * FROM product ORDER BY price DESC")

for row in itr:
    print(row)

conn.close()
