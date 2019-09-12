from sklearn import datasets
from sklearn import cluster
import matplotlib.pyplot as plt

data, label = datasets.make_blobs(n_samples=1000, n_features=2, centers=8, cluster_std=10) 

e = cluster.KMeans(n_clusters=8)
e.fit(data)

print(e.labels_)
print(e.cluster_centers_)

plt.scatter(data[:, 0], data[:, 1], marker="o", c=e.labels_, edgecolor="k")
plt.scatter(e.cluster_centers_[:, 0], e.cluster_centers_[:, 1], marker="x")

plt.show()
