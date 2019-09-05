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
    Name = property(getName)
    Age = property(getAge)
    stdWeight = property(std_weight)

#名前、年齢、身長(cm)でインスタンスを作成
pr1 = Person("田中", 23, 180)
pr2 = Person("渡辺", 25, 160)

#名前、年齢、標準体重を表示
print(pr1.Name, "さん", pr1.Age, "才の標準体重は",pr1.stdWeight,"です。")
print(pr2.Name, "さん", pr2.Age, "才の標準体重は",pr2.stdWeight,"です。")
#BMIを変更
Person.setBmi(21)
#名前、年齢、標準体重を表示
print(pr1.Name, "さん", pr1.Age, "才の標準体重は",pr1.stdWeight,"です。")
print(pr2.Name, "さん", pr2.Age, "才の標準体重は",pr2.stdWeight,"です。")
