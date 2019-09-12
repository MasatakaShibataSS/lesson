import math
import matplotlib.pyplot as plt

x = []
s = []
c = []

for i in range(50):
    x.append(i*0.05*math.pi)
    s.append(math.sin(x[i]))
    c.append(math.cos(x[i]))

plt.title("sin/cos functions")
plt.xlabel("rad")
plt.ylabel("value")
plt.grid(True)

plt.plot(x, s, label="sin")
plt.plot(x, c, label="cos")
plt.legend()

plt.show()
