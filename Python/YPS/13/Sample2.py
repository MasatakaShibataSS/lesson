from sklearn import datasets
from sklearn import cluster
import matplotlib.pyplot as plt
import numpy as np

np.random.seed(0)

data, label = datasets.make_blobs(n_samples=500, n_features=2, centers=5) 

e = cluster.KMeans(n_clusters=5)
e.fit(data)

print(e.labels_)
print(e.cluster_centers_)

plt.scatter(data[:, 0], data[:, 1], marker="o", c=e.labels_, edgecolor="k")
plt.scatter(e.cluster_centers_[:, 0], e.cluster_centers_[:, 1], marker="x")

plt.show()
