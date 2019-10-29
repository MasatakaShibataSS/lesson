# coding: utf-8
import pandas as pd

# 四国電力の電力消費量データを読み込み
ed = [pd.read_csv(
    'shikoku_electricity_%d.csv' % year,
    skiprows=3,
    names=['DATE', 'TIME', 'consumption'],
    parse_dates={'date_hour': ['DATE', 'TIME']},
    index_col='date_hour')
    for year in [2012, 2013, 2014, 2015, 2016]
]

elec_data = pd.concat(ed)

# -- 可視化 --
import matplotlib.pyplot as plt

# 画像のサイズを設定する
plt.figure(figsize=(10, 6))

# ヒストグラム生成
plt.hist(elec_data['consumption'], bins=50, color="gray")
plt.xlabel('electricity consumption(*10000 kW)')
plt.ylabel(u'count')

# グラフ保存
plt.savefig('7-4-1-2-graph.png')
