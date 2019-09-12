str1 = input("文字列を入力してください。")
old = input("置換される文字列を入力してください。")
new = input("置換する文字列を入力してください。")

if old in str1:
    str2 = str1.replace(old, new)
    print(str2, "に置換しました。")
else:
    print(str1 + "の中に" + old + "がみつかりませんでした。")
