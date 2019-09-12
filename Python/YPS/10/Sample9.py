import datetime

dt = datetime.datetime.now()
str = dt.strftime("%c")
print("現在は", str, "です。")

dt = dt + datetime.timedelta(days=1)
str = dt.strftime("%Y-%m-%d")
print("1日後は", str, "です。")
