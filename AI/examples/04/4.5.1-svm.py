# -*- coding: utf-8 -*-

import math

import numpy as np
import matplotlib.pyplot as plt


### バラつきのある正弦波データを作成

x = np.random.rand(1000, 1)  # 0 〜 1 までの乱数を 1000 個つくる
x = x * 20 - 10              # 値の範囲を -10 〜 10 に変更

y = np.array([math.sin(v) for v in x])  # 正弦波カーブ
y += np.random.randn(1000)  # 標準正規分布（平均 0, 標準偏差 1）の乱数を加える


### 学習: Support Vector Machine

from sklearn import svm


model = svm.SVR()
model.fit(x, y)


### 決定係数を表示

r2 = model.score(x, y)
print('決定係数', r2)


### グラフ表示

plt.scatter(x, y, marker='+')
plt.scatter(x, model.predict(x), marker='o')
plt.show()
