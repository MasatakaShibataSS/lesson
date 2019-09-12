from sklearn import datasets
from sklearn import linear_model
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import numpy as np

np.random.seed(0)

x, y = datasets.make_regression(n_samples=100, n_features=1, noise=30)

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3)

e = linear_model.LinearRegression()
e.fit(x_train, y_train)

print("回帰係数は", e.coef_, "です。")
print("切片は", e.intercept_, "です。")

y_pred = e.predict(x_test)

print("学習データによる決定係数は", e.score(x_train, y_train), "です。")
print("テストデータによる決定係数は", e.score(x_test, y_test), "です。")

plt.scatter(x_train, y_train, label="train")
plt.scatter(x_test, y_test, label="test")
plt.plot(x_test, y_pred, color="magenta")
plt.legend()

plt.show()
