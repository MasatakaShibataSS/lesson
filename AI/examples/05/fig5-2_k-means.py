# -*- coding: utf-8 -*-
from __future__ import unicode_literals
import numpy as np
import matplotlib.pyplot as plt
from sklearn import cluster
from sklearn import datasets

# iris データをロード
iris = datasets.load_iris()
data = iris["data"]

# 初期中心点を定義
init_centers=np.array([
       [4,2.5,3,0],
       [5,3  ,3,1],
       [6,4  ,3,2]])

# データ定義と値の取り出し
x_index = 1
y_index = 2

data_x=data[:,x_index]
data_y=data[:,y_index]

# グラフのスケールとラベルの定義
x_max = 4.5
x_min = 2
y_max = 7
y_min = 1
x_label = iris["feature_names"][x_index]
y_label = iris["feature_names"][y_index]

def show_result(cluster_centers,labels):
    # cluster 0と中心点を描画
    plt.scatter(data_x[labels==0], data_y[labels==0],c='black' ,alpha=0.3,s=100, marker="o",label="cluster 0")
    plt.scatter(cluster_centers[0][x_index], cluster_centers[0][y_index],facecolors='white', edgecolors='black', s=300, marker="o")

     # cluster １と中心点を描画
    plt.scatter(data_x[labels==1], data_y[labels==1],c='black' ,alpha=0.3,s=100, marker="^",label="cluster 1")
    plt.scatter(cluster_centers[1][x_index], cluster_centers[1][y_index],facecolors='white', edgecolors='black', s=300, marker="^")

     # cluster と中心点を描画
    plt.scatter(data_x[labels==2], data_y[labels==2],c='black' ,alpha=0.3,s=100, marker="*",label="cluster 2")
    plt.scatter(cluster_centers[2][x_index], cluster_centers[2][y_index],facecolors='white', edgecolors='black', s=500, marker="*")

    # グラフのスケールと軸ラベルを設定
    plt.xlim(x_min, x_max)
    plt.ylim(y_min, y_max)
    plt.xlabel(x_label,fontsize='large')
    plt.ylabel(y_label,fontsize='large')
    plt.show()


# 初期状態を表示
labels=np.zeros(len(data),dtype=np.int)
show_result(init_centers,labels)

for i in range(5):
	model = cluster.KMeans(n_clusters=3,max_iter=1,init=init_centers).fit(data)
	labels = model.labels_
	init_centers=model.cluster_centers_
	show_result(init_centers,labels)

