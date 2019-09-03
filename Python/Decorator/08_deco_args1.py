# @デコレータを使わないプログラム例

# 　このプログラムを@デコレータを使わずに同じ出力結果を得るには、次のようにします。
#デコレータを使わない例
def myfunc():
    print("Message for you : ", end="")

def mydeco(msg):
    def _mydeco(func):
        def wrapper(*args, **kwargs):
            func(*args, **kwargs)
            print(msg)
        return wrapper
    return _mydeco

func = mydeco("Good morning")
f=func(myfunc)
f()
