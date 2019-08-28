data = [74,85,69,77,81]
print("テストの点は", data, "です。")
ndata = [n for n in data if n >= 80]
print("80点以上は", ndata, "です。")
print("80点以上の人数は", len(ndata), "です。")
