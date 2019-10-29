# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
from sklearn import cluster
from sklearn import datasets

# iris データをロード
iris = datasets.load_iris()
data = iris["data"]

# 学習 → クラスタの生成
model = cluster.AffinityPropagation().fit(data)

# 学習結果のラベル取得
labels = model.labels_

### グラフの描画

# クラスタ数がかわるのでマーカは配列で持つ
markers = ["o", "^", "*","v", "+", "x", "d", "p", "s", "1", "2"]

# データ定義
x_index = 2 
y_index = 3

data_x=data[:,x_index]
data_y=data[:,y_index]

x_label = iris["feature_names"][x_index]
y_label = iris["feature_names"][y_index]

# クラスタ毎に散布図を描画
for idx in range(labels.max() + 1):
    plt.scatter(data_x[labels==idx], data_y[labels==idx],
                c='black' ,alpha=0.3,s=100, marker=markers[idx],
                label="cluster {0:d}".format(idx))

# 軸ラベルとタイトルの設定
plt.xlabel(x_label,fontsize='xx-large')
plt.ylabel(y_label,fontsize='xx-large')
plt.title("AffinityPropagation",fontsize='xx-large')

# 凡例表示
plt.legend( loc="upper left" )

plt.show()
