import urllib.request

page = urllib.request.urlopen("https://www.python.org/")

html = page.read()
str = html.decode()

print(str)
