data = ["うお", 1, 2, 3, 4, 5]

for d in map(lambda x: x*10, data):

    print(d)
data = ["うお", 1, 2, 3, 4, 5]
def func(x):
    return x*10

for d in map(func, data):
    print(d, end=" ")
