import random
import matplotlib.pyplot as plt

x = []
y = []

for i in range(100):
    x.append(random.uniform(0, 50))
    y.append(random.uniform(0, 50))

plt.scatter(x, y)
plt.show()
