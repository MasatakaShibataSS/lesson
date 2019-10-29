
# -*- coding: utf-8 -*-


import os
import json
from datetime import datetime

import numpy as np
from matplotlib import pyplot as plt


def visualize_result(
    experiment_name,
    X_test, Y_test, Y_hat, parameters,
    losses=None, save_dir="results"
):
    """
    結果の可視化
    """
    # 保存先ディレクトリが無い場合は作成
    now = datetime.now().strftime("%Y%m%d%H%M%S")
    save_dir += "_" + experiment_name + os.sep + now
    if not os.path.exists(save_dir):
        os.makedirs(save_dir)

    # テストデータの当てはまり（最初の2軸のみ）
    # 表示領域の作成
    plt.figure()
    # 推定値と真値とを同時に表示するため、hold="on"に設定する
    plt.hold("on")
    # x_0 vs y の表示
    plt.subplot(211)
    plt.plot(X_test[:, 0], Y_test, "+", label="True")
    plt.plot(X_test[:, 0], Y_hat, "x", label="Estimate")
    plt.xlabel("x_0")
    plt.ylabel("y")
    plt.legend()
    # x_1 vs y の表示
    plt.subplot(212)
    plt.plot(X_test[:, 1], Y_test, "+")
    plt.plot(X_test[:, 1], Y_hat, "x")
    plt.xlabel("x_1")
    plt.ylabel("y")

    # パラメータをファイルに保存
    # NOTE: json形式は設定ファイルなどのデータ記述に便利な形式です
    #       その実体は構造化テキストファイルです
    #       閲覧する際も適当なテキストエディタを利用してください
    #       pythonの場合、jsonを扱うモジュールが標準で備わっています
    #       （その名もjsonモジュール）
    #       その他のデータ記述の形式としてはyaml, xmlなどがあります
    fn_param = "parameters.json"
    with open(save_dir + os.sep + fn_param, "w") as fp:
        json_str = json.dumps(parameters, indent=4)
        fp.write(json_str)

    # 画像をファイルに保存
    fn_fit = "fitting.png"  # 各種条件
    plt.savefig(save_dir + os.sep + fn_fit)

    # 損失の推移が与えられている場合は表示
    if losses is not None:
        train_losses, test_losses = losses
        # NOTE: 損失の推移は通常指数的なので、
        #       対数スケールで表示することが多いです
        x_train = range(len(train_losses))
        x_test = range(len(test_losses))
        plt.figure()
        plt.plot(
            x_train, np.log(train_losses),
            x_test, np.log(test_losses)
        )
        plt.xlabel("steps")
        plt.ylabel("ln(loss)")
        plt.legend(["training loss", "test loss"])

        fn_loss = "loss.png"
        plt.savefig(save_dir + os.sep + fn_loss)


def flat_nd(xs):
    """
    1つのnumpy.arrayに整形して返します
    """
    return np.c_[tuple([x.flatten() for x in xs])]


def genearate_original_data(
    dimension=2, nonlinear=False, num_of_samples=10000, noise_amplitude=0.1
):
    """
    その他のメソッドで返す変数のもととなるデータを生成します
    """
    # 次元は最低でも2とします
    if dimension < 2:
        raise ValueError("'dimension' must be larger than 2")

    # NOTE: 入力値 x の範囲は決め打ちで[0, 1]としています。
    #       ただし、サンプリングを行う点は一様乱数で決定します。
    x_sample = np.random.rand(num_of_samples, dimension)
    # NOTE: 表示用に、均一でノイズの無いデータも返します
    #       多次元データは表示しても分からないので、
    #       便宜上初めの2次元だけ動かし、
    #       その他の次元は全て定数で固定します
    grid_1d = np.arange(0.0, 1.0, 0.01)
    fixed_coeff = 0.0
    x_grid = flat_nd(np.meshgrid(grid_1d, grid_1d))

    # NOTE: ”正解”の関係式は
    #         f(x) = -1.0 + x_1 + 0.5 * x_2 + Σ_{i>=3} 1/i * x_i
    #                + sin(2πx_1) + cos(2πx_2)
    #                  + Σ_{i>=3, odd} sin(2πx_i)
    #                  + Σ_{i>=4, even} cos(2πx_i)
    #       です。
    #       特に意味のある式ではありません。
    def f(x):
        # 3次以上の項はない場合があります
        higher_terms = x[:, 2:] / np.arange(2, x.shape[1])
        if len(higher_terms) == 0:
            ht_sum = 0.0
        else:
            ht_sum = np.sum(higher_terms, axis=1)

        # まず線形な項を入れます
        y = -1.0 + 1.0 * x[:, 0] + 0.5 * x[:, 1] + ht_sum

        # 非線形フラグが立っていたら非線形項を足します
        if nonlinear:
            if len(higher_terms) == 0:
                ht_sum = 0.0
            else:
                PI2 = np.pi*2
                sin = np.sin(PI2*x[:, 2::2])
                cos = np.cos(PI2*x[:, 3::2])
                ht_sum = np.sum(sin) + np.sum(cos)
            y += np.sin(PI2*x[:, 0]) + np.cos(PI2*x[:, 1]) + ht_sum

        return y

    # 出力値を計算します。
    # NOTE: サンプルされたデータには正規ノイズを付加します。
    noise = noise_amplitude * np.random.randn(x_sample.shape[0])
    y_sample = f(x_sample) + noise

    y_grid = f(x_grid).reshape(x_grid.shape[0])
    # 固定値の追加
    fixed_columns = fixed_coeff * np.ones((x_grid.shape[0], dimension-2))
    x_grid = np.concatenate((x_grid, fixed_columns), axis=1)
    return (
        (x_sample, y_sample),
        (x_grid, y_grid),
    )


def coeff(x):
    """
    生データ x を係数行列に整形して返します
    """
    return np.c_[x, np.ones(x.shape[0])]


def get_all(
    dimension, nonlinear, num_of_samples, noise_amplitude,
    return_coefficient_matrix=True
):
    """
    入力値 x を線形回帰の係数行列、
    出力値 y をベクトルとして、
    全データを一括で返します
    """

    # 元データの取得
    # NOTE: 格子点上の値は不要なので
    #       慣用的に不可視を意味する変数名 _ で受けて無視します
    #       あくまで慣用的な意味づけであって、
    #       実際にはアクセスできる普通の変数なので注意してください
    data_sample, _ = genearate_original_data(
        dimension, nonlinear, num_of_samples, noise_amplitude
    )
    X, Y = data_sample

    # 学習/テストデータを決めるために乱数でインデックスを選択
    N = X.shape[0]
    perm_indices = np.random.permutation(range(N))
    train = perm_indices[:N/2]  # 整数演算なので切り下げ
    test = perm_indices[N/2:]

    # 係数行列として返すか
    if return_coefficient_matrix:
        X = coeff(X)

    return (X[train], Y[train]), (X[test], Y[test])


def get_batch(data, batch_size):
    """
    入力値 x 、出力値 y のタプル data を
    バッチ単位に切り分けて返します
    """
    X, Y = data
    N = len(X)

    # 昇順に整列した非負の整数をpermutationメソッドでシャッフルします
    indices = np.random.permutation(np.arange(N))
    # シャッフルした整数列をバッチサイズで切り出して
    # XとYのインデックスに使います
    data_batch = [
        (X[indices[i: i+batch_size]], Y[indices[i: i+batch_size]])
        for i in range(0, N, batch_size)
    ]

    return data_batch


def main():
    """
    このファイルを単独で実行する場合
    全取得したデータを可視化します。
    """

    # データの数
    num_of_samples = 1000

    # 非線形フラグ
    # True - > 平面
    # False -> 曲面
    nonlinear = False

    # データの生成
    data_sample, data_grid = genearate_original_data(
        nonlinear=nonlinear, num_of_samples=num_of_samples
    )
    x_sample, y_sample = data_sample
    x_grid, y_grid = data_grid

    # 表示用の整形
    num_of_grid_points = int(np.sqrt(len(y_grid)))
    x_grid_0 = x_grid[:, 0].reshape((num_of_grid_points,)*2)
    x_grid_1 = x_grid[:, 1].reshape((num_of_grid_points,)*2)
    y_grid = y_grid.reshape((num_of_grid_points,)*2)

    # NOTE: 図を見ると、等高線の緩やかなところも急なところも
    #       同じような密度で点を取っていることが分かります
    #       （見づらい場合は点数を減らして実行してみてください）。
    #       実際には、関数形をとらえるには急なところの情報が重要ですから、
    #       均一に点が取れればいいというものでもないということが分かります。
    plt.figure()
    plt.contour(x_grid_0, x_grid_1, y_grid, levels=np.arange(-2.0, 2.0, 0.1))
    plt.xlabel("x_0")
    plt.ylabel("x_1")
    plt.title("countour of f(x)")
    plt.hold("on")
    plt.scatter(x_sample[:, 0], x_sample[:, 1], color="k", marker="+")

    plt.savefig("original_data.png")

if __name__ == "__main__":
    main()
