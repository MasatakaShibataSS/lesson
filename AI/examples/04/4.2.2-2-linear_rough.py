# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np


### バラつきのある y = 3x -2 のデータを作成

x = np.random.rand(100, 1)  # 0 〜 1 までの乱数を 100 個つくる
x = x * 4 - 2               # 値の範囲を -2 〜 2 に変更

y = 3 * x - 2  # y = 3x - 2

y += np.random.randn(100, 1)  # 標準正規分布（平均 0, 標準偏差 1）の乱数を加える


### 学習

from sklearn import linear_model


model = linear_model.LinearRegression()
model.fit(x, y)


### 係数、切片、決定係数を表示

print('係数', model.coef_)
print('切片', model.intercept_)

r2 = model.score(x, y)
print('決定係数', r2)


### グラフ表示

plt.scatter(x, y, marker ='+')
plt.scatter(x, model.predict(x), marker='o')
plt.show()
