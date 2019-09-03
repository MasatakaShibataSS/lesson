# 引数を持つ関数のデコレータのプログラム例を次に示します。
# 汎用的なデコレータにするため、可変長引数を使って、さまざまな形式の引数に対応できるようにしています。

def mydeco(func):
    def _mydeco(*args, **kwargs):
        print("{} called".format(func.__name__))
        return func(*args, **kwargs)
    return _mydeco

@mydeco
def args_function(*args):
    print(args)

args_function("hello")

@mydeco
def function():
    print("Hello")

function()
