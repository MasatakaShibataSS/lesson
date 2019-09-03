# デコレータに引数を渡すときは、次のように行います。
# 関数 mydeco(msg) を呼び出すと、戻り値として_mydeco()関数のオブジェクトを返します
# 関数myfunc()を呼び出すとデコレータにより _mydeco(myfunc)として呼び出され、wrapper()関数のオブジェクトを返します
# デコレータによりwrapper()関数のオブジェクトが実行されmyfunc()関数が呼び出されます
def mydeco(msg):
    def _mydeco(func):
        def wrapper(*args, **kwargs):
            func(*args, **kwargs)
            print(msg)
        return wrapper
    return _mydeco

@mydeco("Good morning")
def myfunc():
    print("Message for you : ", end="")

myfunc()

@mydeco("Yes")
def yourfunc(msg):
    print(msg, end="")

yourfunc("Do you like Python? : ")
