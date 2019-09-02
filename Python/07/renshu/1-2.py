inches = [9, 5.5, 6, 4, 5, 6.5, 10]

cms = []
cms = [i*2.54 for i in inches if i > 5]

print(cms)
