import calendar
y = int(input("何年ですか？"))
m = int(input("何月ですか？"))

c = calendar.TextCalendar(5)
c.prmonth(y, m)



# c = calendar.HTMLCalendar()
# c.formatmonth(2019, 9)


calendar.isleap(y)
