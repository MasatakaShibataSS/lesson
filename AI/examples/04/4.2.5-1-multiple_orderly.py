# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np


### y = 3x_1 - 2x_2 + 1 のデータを作成

x1 = np.random.rand(100, 1)  # 0 〜 1 までの乱数を 100 個つくる
x1 = x1 * 4 - 2              # 値の範囲を -2 〜 2 に変更

x2 = np.random.rand(100, 1)  # x2 についても同様
x2 = x2 * 4 - 2

y = 3 * x1 - 2 * x2 + 1


### 学習

from sklearn import linear_model


x1_x2 = np.c_[x1, x2]  # [[x1_1, x2_1], [x1_2, x2_2], ..., [x1_100, x2_100]]
                       # という形に変換

model = linear_model.LinearRegression()
model.fit(x1_x2, y)


### 係数、切片、決定係数を表示

print('係数', model.coef_)
print('切片', model.intercept_)

print('決定係数', model.score(x1_x2, y))


### グラフ表示

y_ = model.predict(x1_x2)  # 求めた回帰式で予測

plt.subplot(1, 2, 1)
plt.scatter(x1, y, marker='+')
plt.scatter(x1, y_, marker='o')
plt.xlabel('x1')
plt.ylabel('y')

plt.subplot(1, 2, 2)
plt.scatter(x2, y, marker='+')
plt.scatter(x2, y_, marker='o')
plt.xlabel('x2')
plt.ylabel('y')

plt.tight_layout()
plt.show()
