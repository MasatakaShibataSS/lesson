class Person:

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def getName(self):
        return self.name

    def getAge(self):
        return self.age

class Student(Person):
    bmi=22
    def __init__(self, nm, ag, height):
        super().__init__(nm, ag)
        self.height = height

    def std_weight(self):
        return Student.bmi * (self.height/100)**2

    def disp(self):
        print(self.name, "さん", self.age, "才の標準体重は", self.std_weight(),"です。")

    @classmethod
    def setBmi(cls, bmi):
        cls.bmi = bmi

#名前、年齢、身長(cm)でインスタンスを作成
pr1 = Student("田中", 23, 180)
pr2 = Student("渡辺", 25, 160)
pr3 = Student("柴田", 40, 177)


#名前、年齢、標準体重を表示
pr1.disp()
pr2.disp()
pr3.disp()

#BMIを変更
Student.setBmi(21)
#名前、年齢、標準体重を表示
pr1.disp()
pr2.disp()
pr3.disp()
