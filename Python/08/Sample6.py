import myclass1

pr = myclass1.Customer("柴田", 40, "mmm@nnn.nn.jp", "xxx-xxx-xxxx")

nm = pr.getName()
ag = pr.getAge()
ad = pr.getAdr()
tl = pr.getTel()

print(nm, "さんは", ag, "歳です。")
print("アドレスは", ad, "電話番号は", tl, "です。")
