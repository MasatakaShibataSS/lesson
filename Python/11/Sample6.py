import urllib.request

page = urllib.request.urlopen("https://www.yahoo.co.jp")

html = page.read()
str = html.decode()

print(str)
