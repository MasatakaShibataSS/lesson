import json

f = open("Sample.json", "r")

data = json.load(f)

print(data)

f.close()
