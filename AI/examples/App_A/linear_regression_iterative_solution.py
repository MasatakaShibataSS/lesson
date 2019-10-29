
# -*- coding: utf-8 -*-

import numpy as np
from get_data import get_all, get_batch, visualize_result, coeff


def raw_gradient(A, E):
    """
    勾配を計算します
    """
    # NOTE: 線形回帰の最小二乗法はデータの塊に対して一つの勾配を計算するため、
    #       ミニバッチ法の説明で延べた
    #       「サンプルごとの勾配の和を取る」という処理はしていません
    return A.T.dot(E)


def momentum_method(
    A, E, current_parameter,
    learning_rate, momentum, regularize_coeff, prev_difference,
):
    """
    モーメント法を適用します
    """
    # Δw := -α * ∇L + β Δw + γ w
    return (
        - learning_rate * raw_gradient(A, E) +  # 勾配
        momentum * prev_difference -  # モーメント
        regularize_coeff * current_parameter  # 罰則項
    )


def train_epoch(data, D_hat, learning_rate, momentum, regularize_coeff):
    """
    1エポック分の学習を実行します
    """
    difference = 0.0
    losses = []
    for step, (X, Y) in enumerate(data):
        # 係数行列に変形
        A = coeff(X)

        # 損失の計算
        E = A.dot(D_hat) - Y
        loss = E.T.dot(E)
        losses.append(loss)

        # 勾配と更新量の計算
        difference = momentum_method(
            A, E, D_hat,  # データ
            learning_rate, momentum, regularize_coeff,  # ハイパーパラメータ
            difference,  # 前回の更新量
        )

        # パラメータを更新
        D_hat += difference

        # 定期的に途中経過を表示
        if step % 100 == 0:
            print("step {0:8}: loss = {1:.4e}".format(step, loss))

    # 損失の平均と、このエポックでの最終推定値を返す
    return np.mean(losses), D_hat


def main():
    # 線形回帰と同様のパラメータ
    # 特徴ベクトルの次元の設定
    dimension = 10
    # 非線形フラグ
    nonlinear = False
    # 全データの数
    num_of_samples = 1000
    # ノイズの振幅
    noise_amplitude = 0.01

    # ハイパーパラメータの設定
    batch_size = 10
    max_epoch = 10000
    learning_rate = 1e-3
    momentum = 0.9  # この値を正にするとモーメント法になります
    regularize_coeff = 0.0  # この値を正にするとL2ノルムによる罰則が掛かります

    # 全データの取得
    # NOTE: ここではミニバッチの挙動のみを見るために、
    #       一旦全データを取得してからバッチ単位に切り出して返しています
    #       しかし、ミニバッチ法が必要になるシチュエーションでは
    #       全データを一気には読み込めないケースが普通ですので、
    #       数バッチ分を読み込んでバッファしてから1バッチだけ返すべきです
    #       このような場合、pythonの機能を活かして
    #       逐次読み込みを行うジェネレータを作成するのが有効です
    data_train, (X_test, Y_test) = get_all(
        dimension, nonlinear, num_of_samples, noise_amplitude,
        return_coefficient_matrix=False
    )
    A_test = coeff(X_test)

    # 損失の履歴
    train_losses = []
    test_losses = []
    # パラメータの初期値
    D_hat = np.zeros(dimension+1)
    # エポックについてのループ
    for epoch in range(max_epoch):
        print("epoch: {0} / {1}".format(epoch, max_epoch))
        # バッチ単位に分割
        data_train_batch = get_batch(data_train, batch_size)
        # 1エポック分学習
        loss, D_hat = train_epoch(
            data_train_batch, D_hat,
            learning_rate, momentum, regularize_coeff
        )

        # 損失を履歴に格納
        train_losses.append(loss)

        # 典型的なコードでは、何エポックかに一度テストを行い、
        # 途中経過がどの程度の汎化性能を示すか確認しますが、
        # ここでは毎回テストを行っています
        Y_hat = A_test.dot(D_hat)
        E = Y_hat - Y_test
        test_loss = E.T.dot(E)
        test_losses.append(test_loss)

    # 実験記録用
    parameters = {
        "linearity": "nonlinear" if nonlinear else "linear",
        "dimension": dimension,
        "num_of_samples": num_of_samples,
        "batch_size": batch_size,
        "max_epoch": max_epoch,
        "learning_rate": learning_rate,
        "momentum": momentum,
        "regularize_coeff": regularize_coeff,
    }
    # 結果の表示
    visualize_result(
        "linear_regression_iterative_solution",
        A_test[:, 0:2], Y_test, Y_hat, parameters,
        losses=(train_losses, test_losses)
    )

if __name__ == "__main__":
    main()
