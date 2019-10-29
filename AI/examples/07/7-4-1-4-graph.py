# coding: utf-8
import pandas as pd

# 気象データを読み込み
tmp = pd.read_csv(
    u'47891_高松.csv',
    parse_dates={'date_hour': ["日時"]},
    index_col="date_hour",
    na_values="×"
)

del tmp["時"]  # 「時」の列は使わないので、削除

# 列の名前に日本語が入っているとよくないので、これから使う列の名前のみ英語に変更
columns = {
    "降水量(mm)": "rain",
    "気温(℃)": "temperature",
    "日照時間(h)": "sunhour",
    "湿度(％)": "humid",
}
tmp.rename(columns=columns, inplace=True)

# -- 可視化 --
import matplotlib.pyplot as plt

plt.figure(figsize=(10, 6))

# ヒストグラム生成

plt.hist(tmp['temperature'], bins=50, color="gray")
plt.xlabel('Temperature(C degree)')
plt.ylabel('count')

# グラフ保存
plt.savefig('7-4-1-4-graph.png')
