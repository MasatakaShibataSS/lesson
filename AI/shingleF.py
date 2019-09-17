# 単回帰分析
# pandasでデータをインポートしてdfに代入
import pandas as pd
df = pd.read_csv('sample.csv')

def predict(h):
    # df内のカラムをx,yに代入
    x = df['x']
    y = df['y']

    # データの中心化
    df_c = df - df.mean()
    xc = df_c['x']
    yc= df_c['y']

    # 傾きaの計算(微分)
    xx = xc * xc
    xy = xc * yc
    a = xy.sum()/xx.sum()

    # 中心化したデータの復元
    xm = x.mean()
    ym =  y.mean()
    xc = h - xm
    y_hat = a * xc + ym

    return y_hat
h = int(input("数値を入力してください\n"))
print(predict(h))
