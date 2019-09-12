import matplotlib.pyplot as plt

data = [8, 17, 0, 11, 6, 21, 16, 6, 17, 11, 
        7, 9, 6, 13, 12, 16, 3, 14, 13, 12]

plt.title("Histogram")

plt.xlabel("value")
plt.ylabel("frequency")

plt.hist(data)
plt.show()
