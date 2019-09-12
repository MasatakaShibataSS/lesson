class Person:
    count = 0

    def __init__(self, name, age):
        Person.count = Person.count + 1

        self.name = name
        self.age = age
      
    def getName(self):
        return self.name

    def getAge(self):
        return self.age

    @classmethod
    def getCount(cls):
        return cls.count

pr1 = Person("鈴木", 23)
pr2 = Person("佐藤", 38)

print(pr1.getName(), "さんは", pr1.getAge(), "才です。")
print(pr2.getName(), "さんは", pr2.getAge(), "才です。")
print("合計人数は", Person.getCount(), "です。")
