import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0.0, 2.5, 0.05)* np.pi
s = np.sin(x)
c = np.cos(x)

plt.title("sin/cos functions")
plt.xlabel("rad")
plt.ylabel("value")
plt.grid(True)

plt.plot(x, s, label="sin")
plt.plot(x, c, label="cos")
plt.legend()

plt.show()
