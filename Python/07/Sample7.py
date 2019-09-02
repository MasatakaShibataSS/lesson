def sell(y = 2019, m = 9, d = 1):
    print(y, "年", m, "月", d, "日に販売が行われました。")

    return y, m, d
sy, sm, sd = sell(1018,10,1)

print("販売終了:", sy, sm, sd)
