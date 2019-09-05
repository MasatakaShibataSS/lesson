class Person:
    bmi=22
    def __init__(self, name, age, height=0):
        self.name = name
        self.age = age
        self.height = height

    def getName(self):
        return self.name

    def getAge(self):
        return self.age

    def std_weight(self):
        return Person.bmi * (self.height/100)**2

    @classmethod
    def setBmi(cls, bmi):
        cls.bmi = bmi
#名前、年齢、身長(cm)でインスタンスを作成
pr1 = Person("田中", 23, 180)
pr2 = Person("渡辺", 25, 160)
#名前、年齢、標準体重を取得
n1 = pr1.getName()
a1 = pr1.getAge()
s1 = pr1.std_weight()

n2 = pr2.getName()
a2 = pr2.getAge()
s2 = pr2.std_weight()
#名前、年齢、標準体重を表示
print(n1, "さん", a1, "才の標準体重は",s1,"です。")
print(n2, "さん", a2, "才の標準体重は",s2,"です。")
#BMIを変更
Person.setBmi(21)
#名前、年齢、標準体重を取得
n1 = pr1.getName()
a1 = pr1.getAge()
s1 = pr1.std_weight()

n2 = pr2.getName()
a2 = pr2.getAge()
s2 = pr2.std_weight()
#名前、年齢、標準体重を表示
print(n1, "さんは", a1, "才の標準体重は",s1,"です。")
print(n2, "さんは", a2, "才の標準体重は",s2,"です。")
