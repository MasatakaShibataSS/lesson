import pandas as pd
df = pd.read_csv('sample.csv')

def predict(h):
    x = df['x']
    y = df['y']
    df_c = df - df.mean()
    xc = df_c['x']
    yc= df_c['y']
    xx = xc * xc
    xy = xc * yc
    a = xy.sum()/xx.sum()
    xm = x.mean()
    ym =  y.mean()
    xc = h - xm
    y_hat = a * xc + ym

    return y_hat
h = int(input("数値を入力してください"))
print(predict(h))
