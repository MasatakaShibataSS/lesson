# Pythonの可変長引数は慣例として (*args, **kwargs) と記述します。
# *args 引数をタプルで受け取ります
# **kwargs 任意の数のキーワード引数を受け取ります
# 関数を呼び出すときに *args と **kwarsg を省略すると引数なしの関数呼び出しになります
def fun(*args, **kwargs):
    print("args: ", args, end='')
    print(" kwargs: ", kwargs)
fun()
fun(1)
fun(key=2)
fun(3,key=4)
fun(5,6,key=7)
fun(8,9,key=10,id=11)
