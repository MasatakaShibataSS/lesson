def deco(func):
    def wrapper(x):
        wx = "---" + x + "---"
        return func(wx)
    return wrapper

@deco
def printmsg(x):
    print(x, "を入力しました。")

str = input("メッセージを入力してください。")

printmsg(str)
