def sell(place, price, num):
    print(place, "支店で", num, "社に", price, "万円の販売が行われました。")
    tt = price * num
    return tt

total1 = sell("東京", 100, 5)
print("売上は", total1, "万円でした。")
sell("東京", 100, 5)
