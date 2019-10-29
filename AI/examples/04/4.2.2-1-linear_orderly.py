# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np


### y = 3x -2 のデータを作成

x = np.random.rand(100, 1)  # 0 〜 1 までの乱数を 100 個つくる
x = x * 4 - 2               # 値の範囲を -2 〜 2 に変更

y = 3 * x - 2  # y = 3x - 2


### 学習

from sklearn import linear_model


model = linear_model.LinearRegression()
model.fit(x, y)


### 係数、切片を表示

print('係数', model.coef_)
print('切片', model.intercept_)


### グラフ表示

plt.scatter(x, y, marker='+')
plt.show()
