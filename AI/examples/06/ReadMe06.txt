『Pythonによる機械学習入門 6章 画像による手形状分類』サンプルコードについて。
2016-11-28 ISP

[使い方]
・data.zipはスクリプトと同じフォルダにフォルダ付きで展開してください。

・スクリプトはコンソールから実行する想定です。
 （P140のHOGの可視化のみコマンドライン想定）
  引数の指定が必須であることにご注意ください。

・以下 本書中の起動スクリプトを掲載しておきます。
P122
  run trial_handsign_SVM.py ./data/my_learn8/ ./data/my_test2/
  run trial_handsign_SVM.py ./data/my_learn10/ ./data/other_test2/

P126
  run classify_handsign_1.py 1 ./data/m01 ./data/m02 ./data/m03 ./data/m04
  run classify_handsign_1.py 1 ./data/other_test2 ./data/m02 ./data/m03 ./data/m04

P128
  run classify_handsign_1.py 4 ./data/m01 ./data/m05 ./data/m06 ./data/m07 ./data/m02 ./data/m03 ./data/m04 ./data/m08 ./data/m09 ./data/m10 ./data/m11 ./data/m12 ./data/m13 ./data/m14 ./data/m15 ./data/m16

P130
  run classify_handsign_2.py 4 ./data/m01 ./data/m05 ./data/m06 ./data/m07 ./data/m02 ./data/m03 ./data/m04 ./data/m08 ./data/m09 ./data/m10 ./data/m11 ./data/m12 ./data/m13 ./data/m14 ./data/m15 ./data/m16

P136
  run classify_handsign_2.py 4 ./data/m01 ./data/m05 ./data/m06 ./data/m07 ./data/m02 ./data/m03 ./data/m04c ./data/m08 ./data/m09 ./data/m10 ./data/m11 ./data/m12 ./data/m13 ./data/m14 ./data/m15 ./data/m16

P140
  # これはコマンドライン実行の場合です。
  python viewHOG40.py ./data/m01/2/01_2_001.png

  # IPythonを含むpythonコンソールの場合は以下のように実行します。
  run viewHOG40.py ./data/m01/2/01_2_001.png

P142
  run classify_handsign_HOG_2.py 4 ./data/m01 ./data/m05 ./data/m06 ./data/m07 ./data/m02 ./data/m03 ./data/m04c ./data/m08 ./data/m09 ./data/m10 ./data/m11 ./data/m12 ./data/m13 ./data/m14 ./data/m15 ./data/m16

P148
  run classify_handsign_HOG_2.py 4 ./data/m01 ./data/m05 ./data/m06 ./data/m07 ./data/m02 ./data/m03 ./data/m04c ./data/m08 ./data/m09 ./data/m10 ./data/m11 ./data/m12 ./data/m13 ./data/m14 ./data/m15 ./data/m16

[修正箇所]
・P124 リスト6-2
  60行目、61行目  print文の括弧を追加

・P129 リスト6-3
  60行目、61行目  print文の括弧を追加 


以上