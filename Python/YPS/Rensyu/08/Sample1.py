class Car():

    def __init__(self, num, gas):
        self.num = num
        self.gas = gas
    def getNumber(self):
        return self.num

    def getGas(self):
       return self.gas

cr1 = Car(1234, 25.5)
n1 = cr1.getNumber()
g1 = cr1.getGas()

cr2 = Car(2345, 30.5)
n2 = cr2.getNumber()
g2 = cr2.getGas()

print("ナンバーは", n1, "ガソリン量は", g1, "です。")
print("ナンバーは", n2, "ガソリン量は", g2, "です。")
