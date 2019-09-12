# 単回帰分析の初期モデル
# numpyで算出した結果を変数に代入


def predict(x):
    a = 10069.022519284063
    xm = 37.62222
    ym = 121065.0

    xc = x - xm
    y_hat = a * xc + ym

    return y_hat
x = int(input("数値を入力してください"))
print(predict(x))
