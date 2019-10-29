# -*- coding: utf-8 -*- 
import os
import sys
import glob
import numpy as np
from skimage import io
from sklearn import datasets

IMAGE_SIZE = 40
COLOR_BYTE = 3
CATEGORY_NUM = 6

## ラベル名(0～)を付けたディレクトリに分類されたイメージファイルを読み込む
## 入力パスはラベル名の上位のディレクトリ
def load_handimage(path):

    # ファイル一覧を取得
    files = glob.glob(os.path.join(path, '*/*.png'))

    # イメージとラベル領域を確保
    images = np.ndarray((len(files), IMAGE_SIZE, IMAGE_SIZE,
                            COLOR_BYTE), dtype = np.uint8)
    labels = np.ndarray(len(files), dtype=np.int)

    # イメージとラベルを読み込み
    for idx, file in enumerate(files):
       # イメージ読み込み
       image = io.imread(file)
       images[idx] = image

       # ディレクトリ名よりラベルを取得
       label = os.path.split(os.path.dirname(file))[-1]
       labels[idx] = int(label)

    # scikit-learn の他のデータセットの形式に合わせる
    flat_data = images.reshape((-1, IMAGE_SIZE * IMAGE_SIZE * COLOR_BYTE))
    images = flat_data.view()
    return datasets.base.Bunch(data=flat_data,
                 target=labels.astype(np.int),
                 target_names=np.arange(CATEGORY_NUM),
                 images=images,
                 DESCR=None)

#####################################
from sklearn import svm, metrics

## usage:
##    python classify_handsign_1.py <n> <dir_1> <dir_2> ... <dir_m>
##      n          テスト用データディレクトリ数
##      dir_1      データディレクトリ1
##      dir_m      データディレクトリm

if __name__ == '__main__':
    argvs = sys.argv
    
    # 評価用ディレクトリ数の取得
    paths_for_test = argvs[2:2+int(argvs[1])]
    paths_for_train = argvs[2+int(argvs[1]):]
    
    print('test ', paths_for_test)
    print('train', paths_for_train)

    # 評価データの読み込み
    data = []
    label = []
    for i in range(len(paths_for_test)):
        path = paths_for_test[i]
        d = load_handimage(path)
        data.append(d.data)
        label.append(d.target)
    test_data = np.concatenate(data)
    test_label = np.concatenate(label)

    # 学習データの読み込み
    data = []
    label = []
    for i in range(len(paths_for_train)):
        path = paths_for_train[i]
        d = load_handimage(path)
        data.append(d.data)
        label.append(d.target)
    train_data = np.concatenate(data)
    train_label = np.concatenate(label)

    # 手法:線形SVM
    classifier = svm.LinearSVC()
    
    # 学習
    classifier.fit(train_data, train_label)

    # テスト
    predicted = classifier.predict(test_data)

    # 結果表示
    print("Accuracy:\n%s" % metrics.accuracy_score(test_label, predicted))
