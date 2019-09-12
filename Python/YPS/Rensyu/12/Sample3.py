import random
import matplotlib.pyplot as plt

data = []

for i in range(1000):
    data.append(random.normalvariate(0, 10))

plt.title("Histogram")

plt.hist(data, bins=50)
plt.show()
