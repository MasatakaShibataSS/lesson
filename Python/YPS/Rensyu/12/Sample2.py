import random
import matplotlib.pyplot as plt

x = []
y = []

for i in range(100):
    x.append(random.uniform(0, 50))
    y.append(random.uniform(0, 50))

v = [-100, 100, -100, 100]
plt.axis(v)

plt.scatter(x, y, marker="x")
plt.show()
