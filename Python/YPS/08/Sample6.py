import myclass

pr = myclass.Customer("鈴木", 23, "mmm@nnn.nn.jp", "xxx-xxx-xxxx")

nm = pr.getName()
ag = pr.getAge()
ad = pr.getAdr()
tl = pr.getTel()

print(nm, "さんは", ag, "才です。")
print("アドレスは", ad, "電話番号は", tl, "です。")
