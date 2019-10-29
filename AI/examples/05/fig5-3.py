import matplotlib.pyplot as plt
from sklearn import cluster
from sklearn import datasets

# iris データをロード
iris = datasets.load_iris()
data = iris['data']

# 学習 → クラスタの生成
model = cluster.KMeans(n_clusters=3)
model.fit(data)

# 学習結果のラベル取得
labels = model.labels_

# グラフの描画
ldata = data[labels == 0]
plt.scatter(ldata[:, 2], ldata[:, 3],
                  c='black' ,alpha=0.3,s=100 ,marker="o")

ldata = data[labels == 1]
plt.scatter(ldata[:, 2], ldata[:, 3],
                  c='black' ,alpha=0.3,s=100 ,marker="^")

ldata = data[labels == 2]
plt.scatter(ldata[:, 2], ldata[:, 3],
                  c='black' ,alpha=0.3,s=100 ,marker="*")

# 軸ラベルの設定
plt.xlabel(iris["feature_names"][2],fontsize='large')
plt.ylabel(iris["feature_names"][3],fontsize='large')

plt.show()
