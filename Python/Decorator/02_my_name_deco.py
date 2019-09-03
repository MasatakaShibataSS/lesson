# @関数名を使って記述すると次のようになります。
def name(func):
    def my_name():
        return "my name is " +func()
    return my_name

@name
def hoge():
    return "hoge"

print(hoge())
