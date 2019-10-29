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

# 気象データを読み込み
tmp = pd.read_csv(
    u'47891_高松.csv',
    parse_dates={'date_hour': ["日時"]},
    index_col="date_hour",
    low_memory=False,
    na_values=["×", "--"]
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
tmp.fillna(-1,inplace=True)

# 月, 日, 時の取得
tmp["month"] = tmp.index.month
tmp['day'] = tmp.index.day
tmp['dayofyear'] = tmp.index.dayofyear
tmp['hour'] = tmp.index.hour

# 気象データと電力消費量データをいったん統合して時間軸を合わせたうえで、再度分割
takamatsu = elec_data.join(tmp[["temperature","sunhour","month","hour"]]).dropna().as_matrix()

takamatsu_elec = takamatsu[:, 0:1]
takamatsu_wthr = takamatsu[:, 1:]

# 学習と性能の評価
import sklearn.cross_validation
import sklearn.svm
model = sklearn.svm.SVR()



x_train, x_test, y_train, y_test = sklearn.cross_validation.train_test_split(
    takamatsu_wthr, takamatsu_elec, test_size=0.2)

y_train = y_train.flatten()
y_test = y_test.flatten()

model.fit(x_train, y_train)
date_name = ["気温", "日照時間","月","時間"]

output = "使用項目 = %s, 訓練スコア = %f, 検証スコア = %f" % \
         (", ".join(date_name),
          model.score(x_train, y_train),
          model.score(x_test, y_test)
          )
#    print (output.decode('utf-8')) # Python2の場合こちらの行を使ってください
print (output)  # Python3向け



# -- 可視化 --
import matplotlib.pyplot as plt

# 画像のサイズを設定する
plt.figure(figsize=(10, 6))

predicted = model.predict(x_test)

plt.xlabel('electricity consumption(measured *10000 kW)')
plt.ylabel('electricity consumption(predicted *10000 kW)')
plt.scatter(y_test, predicted, s=0.5, color="black")

plt.savefig("7-5-5-4-graph.png")


