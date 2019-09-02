inches = [9, 5.5, 6, 4, 5, 6.5, 10]

cms = []
for inch in filter(lambda inch: inch > 5, inches):

    cms.append(inch * 2.54)
print(cms)
