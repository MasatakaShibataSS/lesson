import datetime

dt = datetime.datetime.now()
str = dt.strftime("%c")

dt = dt + datetime.timedelta(days=1)
str = dt.strftime("%Y-%m-%d")
print("１日後は", str, "です。")
