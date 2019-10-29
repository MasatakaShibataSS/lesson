#各方程式を設定するためにNumPyをインポート
import numpy as np
# matplotlibのpyplotをpltでインポート
import matplotlib.pyplot as plt

# x軸の領域と精度を設定し、x値を用意
x = np.arange(-3, 3, 0.1)

#各方程式のy値を用意
y_sin = np.sin(x)
x_rand = np.random.rand(100) * 6 - 3
y_rand = np.random.rand(100) * 6 - 3

# figureオブジェクトを作成
plt.figure()

# 1つのグラフで表示する設定
plt.subplot(1, 1, 1)

#各方程式の線形とマーカー、ラベルを設定し、プロット
##線形図
plt.plot(x, y_sin, marker='o', markersize=5, label='line')

##散布図
plt.scatter(x_rand, y_rand, label='scatter')

#凡例表示を設定
plt.legend()
#グリッド線を表示
plt.grid(True)

#グラフ表示
plt.show()
