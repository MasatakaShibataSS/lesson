
# -*- coding: utf-8 -*-

import time
import numpy as np

# データ取得および結果の可視化を行うメソッドは
# 外部のモジュールget_data.pyにて定義します。
from get_data import get_all, visualize_result


def main():
    # 実験用パラメータの設定
    # dimension, nonlinear, num_of_samplesを変えて結果を見比べてみてください
    # NOTE: これらは実験のためのデータセット自体を変更するものなので
    #       アルゴリズムの動作を規定するハイパーパラメータとは異なります

    # 特徴ベクトルの次元
    dimension = 100
    # 非線形フラグ
    # True  -> 超平面
    # False -> 超曲面
    # 線形回帰は超平面のモデルなので、当然Falseの方がよい推定結果を与えます
    nonlinear = False
    # 全データの数
    num_of_samples = 1000
    # ノイズの振幅
    noise_amplitude = 0.01

    # 全データの取得
    # NOTE: テストデータには目印 '_test' を付けていますが、
    #       学習用データについては、計算を実行するコード中で式が見やすいように
    #       '_train'のような目印はつけていません
    (A, Y), (A_test, Y_test) = get_all(
        dimension, nonlinear, num_of_samples, noise_amplitude
    )

    # 逆行列による推定値
    start = time.time()
    # (A^tA)^(-1) A^t Y を直接計算
    D_hat_inv = (np.linalg.inv(A.T.dot(A)).dot(A.T)).dot(Y)
    print("D_hat_inv: {0:.16f}[s]".format(time.time() - start))

    # 連立方程式の求解による推定値
    start = time.time()
    # A.tA * D = A.t Y を D について解く
    D_hat_slv = np.linalg.solve(A.T.dot(A), A.T.dot(Y))
    print("D_hat_slv: {0:.16f}[s]".format(time.time() - start))

    # 2つの解の差
    dD = np.linalg.norm(D_hat_inv - D_hat_slv)
    print("difference of two solutions: {0:.4e}".format(dD))

    # NOTE: 2つの解にあまり差がないことが確認できるので、
    #       以下のプロットではD_hat_slvのみを利用しています
    # テストデータへのフィッティング
    Y_hat = A_test.dot(D_hat_slv)
    mse = np.linalg.norm(Y_test-Y_hat) / dimension
    print("test error: {:.4e}".format(mse))

    # 実験記録用
    parameters = {
        "linearity": "nonlinear" if nonlinear else "linear",
        "dimension": dimension,
        "num_of_samples": num_of_samples,
    }
    # 結果の表示
    # NOTE: 表示用に2次元だけ渡しています
    visualize_result(
        "linear_regression_analytic_solution",
        A_test[:, :2], Y_test, Y_hat, parameters
    )

if __name__ == "__main__":
    main()
