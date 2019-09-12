import sqlite3

conn = sqlite3.connect("pdb.db")

c = conn.cursor()

c.execute("DROP TABLE IF EXISTS product")

c.execute("CREATE TABLE product(name CHAR(20), price INT)")
c.execute("INSERT INTO product VALUES('鉛筆', 80)")
c.execute("INSERT INTO product VALUES('消しゴム', 50)")
c.execute("INSERT INTO product VALUES('定規', 200)")
c.execute("INSERT INTO product VALUES('コンパス', 300)")
c.execute("INSERT INTO product VALUES('ボールペン', 100)")

conn.commit()

itr = c.execute("SELECT * FROM product")

for row in itr:
    print(row)

conn.close()
