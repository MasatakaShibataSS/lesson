# このプログラムは@デコレータを使わないと次の例と等価になります。
def hello():
    return "hello world"

def makebold(fn):
    def wrapped():
        return "<b>" + fn() + "</b>"
    return wrapped

def makeitalic(fn):
    def wrapped():
        return "<i>" + fn() + "</i>"
    return wrapped

hello = makebold(makeitalic(hello))
print(hello())
