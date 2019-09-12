import pandas as pd
df = pd.read_csv('sample.csv')

def predict(x):
    x = df['x']
    y = df['y']
    df_c = df - df.mean()
    x = df_c['x']
    y = df_c['y']
    xx = x * x
    xy = x * y
    a = xy.sum()/xx.sum()
    xm = mean['x']
    ym = mean['y']

    xc = x - xm
    y_hat = a * xc + ym

    return y_hat
x = int(input("数値を入力してください"))
print(predict(x))
