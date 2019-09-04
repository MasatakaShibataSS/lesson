class Person:

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def getName(self):
        return self.name

    def getAge(self):
        return self.age

    def setName(self,name):
        self.name = name

    def setAge(self,age):
        self.age = age

pr = Person("鈴木", 23)

n = pr.getName()
a = pr.getAge()

print(n,"さんは", a, "歳です。")

pr.setName("佐藤")
pr.setAge(29)

n = pr.getName()
a = pr.getAge()

print(n,"さんは", a, "歳です。")
