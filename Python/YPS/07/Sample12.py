a = 0

def func():
    global a
    b = 0
    
    print("変数aは", a, "変数bは", b)
    
    a = a+1
    b = b+1

for i in range(5):
    func()
