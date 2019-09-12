import sqlite3

conn = sqlite3.connect("pdb.db")

c = conn.cursor()

c.execute("DROP TABLE IF EXISTS product")

c.execute("CREATE TABLE product(name CHAR(20), num INT)")
c.execute("INSERT INTO product VALUES('みかん', 80)")
c.execute("INSERT INTO product VALUES('いちご', 60)")
c.execute("INSERT INTO product VALUES('りんご', 22)")
c.execute("INSERT INTO product VALUES('もも', 50)")
c.execute("INSERT INTO product VALUES('くり', 75)")

conn.commit()

itr = c.execute("SELECT * FROM product")

for row in itr:
    print(row)

conn.close()
