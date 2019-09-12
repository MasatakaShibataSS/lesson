str = input("文字列を入力してください。")
key = input("検索する文字列を入力してください")

res = str.find(key)

if res != -1:
    print(str, "の", res, "の位置に", key, "がみつかりました。")
else:
    print(str,  "の中に", key, "がみつかりませんでした。")
