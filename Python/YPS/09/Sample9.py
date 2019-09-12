import re

ptr = ["[012]", "[0-3]", "[^012]"]
str = ["0", "1", "2", "3"]

for valueptr in ptr:
    print("------")
    pattern = re.compile(valueptr)
    for valuestr in str:
        res = pattern.search(valuestr)
        if res is not None:
            m = "〇"
        else:
            m = "×"
        msg = "（パターン）" + valueptr + "（文字列）" + valuestr + "（マッチ）" + m
        print(msg)
