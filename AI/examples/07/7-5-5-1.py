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

tmp = tmp[["temperature","sunhour"]]
ld = tmp

h_count = 2
for i in range(1,h_count):
    ld = ld.join(tmp.shift(i),rsuffix="_"+str(i)).dropna()

tmp = ld
## データの結合  
takamatsu = elec_data.join(tmp).dropna().as_matrix()

takamatsu_elec = takamatsu[:, 0:1]
takamatsu_wthr = takamatsu[:, 1:]

# 学習と性能の評価
import sklearn.cross_validation
import sklearn.svm

data_count = len(takamatsu_elec)

# 交差検定の準備
kf = sklearn.cross_validation.KFold(data_count, n_folds=5)

# 交差検定実施(全てのパターンを実施)
for train, test in kf:
    x_train = takamatsu_wthr[train]
    x_test = takamatsu_wthr[test]
    y_train = takamatsu_elec[train]
    y_test = takamatsu_elec[test]

    # -- SVR --
    model = sklearn.svm.SVR()
    y_train = y_train.flatten()
    y_test = y_test.flatten()

    model.fit(x_train, y_train)
    print ("SVR: Training Score = %f, Testing(Validate) Score = %f" %
           (model.score(x_train, y_train), model.score(x_test, y_test)))
