# デコレータでHTMLタグ生成
# デコレータに引数を渡すことができると、次のようにHTMLタグを効率的に作ることができます。
def html_tag(tag):
    def _html_tag(func):
        def wrapper(*args,**kwargs):
            res = '<'+tag+'>'
            res = res + func(*args,**kwargs)
            res = res + '</'+tag+'>'
            return res
        return wrapper
    return _html_tag

@html_tag('html')
@html_tag('body')
def hello():
    return 'Hello Decorator!'

print(hello())
#>>>print(hello())
#<html><body>Hello Decorator!</body></html>
