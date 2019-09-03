a = 0

def func():
    global a
    b = 20
    print(id(b))

    print("変数aの値は", a, "変数bの値は", b)

    a = a+1
    b = b+1

for i in range(5):
    func()
