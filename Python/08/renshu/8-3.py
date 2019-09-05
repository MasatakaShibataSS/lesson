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
pr1.disp()
pr2.disp()
#BMIを変更
Person.setBmi(21)
#名前、年齢、標準体重を表示
pr1.disp()
pr2.disp()
