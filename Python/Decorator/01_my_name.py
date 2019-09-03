# @関数名を使わずに記述
def hoge():
    return "hoge"

def name(func):
    def my_name():
        return "my name is " +func()
    return my_name

hoge = name(hoge)
print(hoge())
