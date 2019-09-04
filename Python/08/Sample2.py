class Person:

    def getName(self):
        return self.name

    def getAge(self):
        return self.age

pr1 = Person()
pr1.name ="鈴木"
pr1.age = 23
n1 = pr1.getName()
a1 = pr1.getAge()

pr2 = Person()
pr2.name ="佐藤"
pr2.age = 38
n2 = pr2.getName()
a2 = pr2.getAge()

print(n1,"さんは", a1, "歳です。")
print(n2,"さんは", a2, "歳です。")

people = [Person(), Person()]
people[0].name = "山田"
people[0].age = 20

n0 = people[0].getName()
a0 = people[0].getAge()
print(n0,"さんは", a0, "歳です。")
