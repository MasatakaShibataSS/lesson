import urllib.request
from html.parser import HTMLParser

class SampleHTMLParser(HTMLParser):
    def __init__(self):
        HTMLParser.__init__(self)
        self.title = False

    def handle_starttag(self, tag, attrs):
        if tag == "title":
            self.title = True

    def handle_data(self, data):
        if self.title is True:
            print("タイトル：", data)
            self.title = False

page = urllib.request.urlopen("http://www.python.org")

html = page.read()
str = html.decode()

p = SampleHTMLParser()
p.feed(str)

p.close()
