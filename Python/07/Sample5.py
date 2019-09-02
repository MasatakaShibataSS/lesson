def sell(place, num1=10, num2=5):
    print(place, "支店で", num1+num2, "万円の販売が行われました。")
    print("num2= ", num2)

# sell(20)
sell("東京")
sell("東京", 20,5)
sell("東京", num2=20, num1=10)
