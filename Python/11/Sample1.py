import sqlite3
conn = sqlite3.connect("pdb.db")

c = conn.cursor()

c.exrcute("DROP TABLE IF EXISTS product")

c.exrcute("CREATE TABLE product(name CHAR(20), price INT)")
