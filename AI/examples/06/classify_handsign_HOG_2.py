# -*- coding: utf-8 -*- 
import os
import sys
import glob
import numpy as np
from skimage import io
from sklearn import datasets
from skimage.feature import hog

CATEGORY_NUM = 6

## ラベル名(0～)を付けたディレクトリに分類されたイメージファイルを読み込む
## 入力パスはラベル名の上位のディレクトリ
def load_handimage(path):

    # ファイル一覧を取得
    files = glob.glob(os.path.join(path, '*/*.png'))

    # イメージとラベル領域を確保
    hogs = np.ndarray((len(files), 3600), dtype = np.float)
    labels = np.ndarray(len(files), dtype=np.int)

    # イメージとラベルを読み込み
    for idx, file in enumerate(files):
        # イメージ読み込み
        image = io.imread(file, as_grey=True)
        h = hog(image, orientations=9, pixels_per_cell=(5, 5),
            cells_per_block=(5, 5))
        hogs[idx] = h

        # ディレクトリ名よりラベルを取得
        label = os.path.split(os.path.dirname(file))[-1]
        labels[idx] = int(label)

    return datasets.base.Bunch(data=hogs,
                 target=labels.astype(np.int),
                 target_names=np.arange(CATEGORY_NUM),
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

    for path in paths_for_test:
        # テストデータの読み込み
        d = load_handimage(path)
        
        # テスト
        predicted = classifier.predict(d.data)

        # 結果表示
        print("### %s ###" % path)
        print("Accuracy:\n%s"
            % metrics.accuracy_score(d.target, predicted))
        print("Classification report:\n%s\n"
            % metrics.classification_report(d.target, predicted))
