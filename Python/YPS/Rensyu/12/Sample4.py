import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-8, 8, 0.01)
y1 = 3*x+5
y2 = x**2

plt.title("y=f(x)")
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)

plt.plot(x, y1)
plt.plot(x, y2)

plt.show()
