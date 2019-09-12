class Person:

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def getName(self):
        return self.name

    def getAge(self):
        return self.age

class Customer(Person):
    def __init__(self, nm, ag, ad, tl):
        super().__init__(nm, ag)

        self.adr = ad
        self.tel = tl

    def getName(self):
        self.name = "顧客：" + self.name
        return self.name

    def getAdr(self):
        return self.adr

    def getTel(self):
        return self.tel

pr = Customer("鈴木", 23, "mmm@nnn.nn.jp", "xxx-xxx-xxxx")

nm = pr.getName()
ag = pr.getAge()
ad = pr.getAdr()
tl = pr.getTel()

print(nm, "さんは", ag, "才です。")
print("アドレスは", ad, "電話番号は", tl, "です。")
