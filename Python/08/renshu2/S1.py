import carclass

cr1 = carclass.Car("1234", 23.5)
cr2 = carclass.Car("2345", 30.5)

n1 = cr1.getNum()
g1 = cr1.getGas()


n2 = cr2.getNum()
g2 = cr2.getGas()

print("ナンバーは", n1, "ガソリン量は", g1, "です。")
print("ナンバーは", n2, "ガソリン量は", g2, "です。")
