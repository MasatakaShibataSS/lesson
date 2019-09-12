import datetime

dt = datetime.datetime.now()
print("現在は", dt, "です。")
print("年：", dt.year)
print("月：", dt.month)
print("日：", dt.day)

dt = dt + datetime.timedelta(days=1)
print("1日後は", dt, "です。")
