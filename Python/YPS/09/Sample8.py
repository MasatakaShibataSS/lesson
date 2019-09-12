import re

ptr = ["TXT.", "TXT..", ".TXT", "..TXT"]
str = ["TXT", "TXTT", "TXTTT", "TTXT", "TTTXT"]

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
