try:
    f = open("Sample.txt", "r")
   
except FileNotFoundError:
    print("ファイルをオープンできませんでした。")

else:
    lines = f.readlines()
    for line in lines:
       print(line, end="")
    f.close()

finally:
    print("処理を終了します。")
