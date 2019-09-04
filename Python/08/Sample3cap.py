class Person:

    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    def getName(self):
        return self.__name

    def getAge(self):
        return self.__age

    def setName(self,name):
        self.__name = name
        return self.__name

    def setAge(self,age):
        if age >= 0:
            self.__age = age
        return self.__age


    age = property(getAge)

pr = Person("鈴木", 23)

n = pr.getName()
a = pr.getAge()

print(n,"さんは", a, "歳です。")

pr.setName("佐藤")
pr.setAge(29)

print(n,"さんは", a, "歳です。")
print(pr.age)
