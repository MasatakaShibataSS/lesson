
# -*- coding: utf-8 -*-

import numpy as np
from get_data import get_all, get_batch, visualize_result


# シグモイド計算時に許容する最小値
FLOOR = np.log(np.spacing(1))


def backward(
    Z, E, W, learning_rate, momentum, regularize_coeff, prev_difference
):
    """
    誤差逆伝搬の計算を実行します
    """
    # ハイパーパラメータを埋め込んだ
    # ローカルな関数オブジェクトを作成
    def dW(e, z, w, pd):
        """
        単純な勾配にモーメント法を適用し、
        バッチ内の和を取って返します
        """
        # NOTE: 第0成分がサンプルを表すため、
        #       ベクトル同士の積がうまく書けません
        #       その代わり、ブロードキャストを使って総当たりの積を取っています
        g = e[:, :, np.newaxis] * z[:, np.newaxis, :]
        dW_batch = momentum_method(
            g, w, learning_rate, momentum, regularize_coeff, pd
        )
        return np.sum(dW_batch, axis=0)

    # NOTE: 最終層にシグモイドを掛けていないため、
    #       本文中の式で言うところの最終層の更新則の式は利用していません
    #       シグモイドをかける場合、ここに
    #         E = grad_sigmoid(Z[-1]) * E
    #       を挿入します

    # 更新量
    d = [dW(E, Z[-2], W[-1], prev_difference[-1])]
    # 出力と重みを逆向きに辿ります
    # NOTE: _Zp は f(u^(k)) , _Zn は z_k に相当します
    for _Wp, _Wn, _Zp, _Zn, pd in zip(
        W[-1::-1], W[-2::-1], Z[-2::-1], Z[-3::-1], prev_difference[-2::-1]
    ):
        # 一つ先の層の誤差から単純な勾配法の更新量を計算
        E = (_Zp*(1-_Zp)) * E.dot(_Wp)
        # モーメント法を適用した値を格納
        d.insert(0, dW(E, _Zn, _Wn, pd))

    # NOTE: 線形回帰のコードに合わせて更新量を返すメソッドにしていますが、
    #       このメソッドの中で更新を行ってもOKです
    return d


def forward(X, W):
    """
    順方向の計算を実行します
    """
    Z = [X]
    for _W in W[:-1]:
        # NOTE: 各バッチを第0成分に格納しているため、
        #       式とは異なり転置を取った表現になっています
        Z.append(sigmoid(Z[-1].dot(_W.T)))
    # 回帰問題を解く都合上、最終層ではシグモイドを掛けません
    # シグモイドの値域は[0, 1]であり、任意の実数を出力できないからです
    Z.append(Z[-1].dot(W[-1].T))
    return Z


def sigmoid(X):
    """
    要素ごとのシグモイドの計算を実行します
    """
    # そのままXを使うと、負の大きな値でオーバーフローを起こします
    # これを避けるため、全ての要素をゼロで初期化しておき、
    # 十分大きなXのみ実際の計算に利用します
    out = np.zeros(X.shape)
    stable = (X > FLOOR)  # 安定な領域
    out[stable] = 1/(1+np.exp(-X[stable]))
    return out


def momentum_method(
    raw_gradient, current_parameter,
    learning_rate, momentum, regularize_coeff, prev_difference,
):
    """
    モーメント法を適用します
    """
    # Δw := -α * ∇L + β Δw - γ w
    return (
        - learning_rate * raw_gradient +  # 勾配
        momentum * prev_difference -   # モーメント
        regularize_coeff * current_parameter  # 罰則項
    )


def train_epoch(data, W_hat, learning_rate, momentum, regularize_coeff):
    """
    1エポック分の学習を実行します
    """
    difference = [0.0]*len(W_hat)
    losses = []
    for step, (X, Y) in enumerate(data):
        # 損失の計算
        # 順方向の計算
        Z = forward(X, W_hat)

        # 最終層の誤差
        # NOTE: Z[-1]の次元(m, 1)と揃えるため
        #       Yにも次元を加えています
        E = Z[-1] - Y[:, np.newaxis]
        loss = E[:, 0].T.dot(E[:, 0])
        losses.append(loss)

        # 勾配と更新量の計算
        difference = backward(
            Z, E,  # データおよび中間層の出力と誤差
            W_hat,  # パラメータ
            learning_rate, momentum, regularize_coeff,  # ハイパーパラメータ
            difference,  # 前回の更新量
        )

        # パラメータを更新
        for _W_hat, _difference in zip(W_hat, difference):
            _W_hat += _difference

        # 定期的に途中経過を表示
        if step % 100 == 0:
            print("step {0:8}: loss = {1:.4e}".format(step, loss))

    # 損失の平均と、このエポックでの最終推定値を返す
    return np.mean(losses), W_hat


def init_weights(num_units, prev_num_unit):
    W = []
    # NOTE: 最終層は1次元なので、num_unitsに[1]を加えています
    for num_unit in num_units+[1]:
        # 重みのサイズは（現在の層のユニット数, 直前の層のユニット数）です
        # NOTE: 誤差は重みづけられて伝搬するため、
        #       初期値がゼロだと更新が行われません
        #       ここでは正規乱数によって初期化しています
        #       この際、標準偏差を
        #         √(2.0/prev_num_unit)
        #       として与えると収束しやすいということが知られています
        #       python2系列で実行する場合、2とすると整数の除算になってしまうので注意してください
        random_weigts = np.random.randn(num_unit, prev_num_unit)
        normalized_weights = np.sqrt(2.0/prev_num_unit) * random_weigts
        W.append(normalized_weights)
        prev_num_unit = num_unit
    return W


def main():
    # 線形回帰と同様のパラメータ
    # 特徴ベクトルの次元の設定
    dimension = 10
    # 非線形フラグ
    nonlinear = True
    # 全データの数
    num_of_samples = 1000
    # ノイズの振幅
    noise_amplitude = 0.01

    # 線形回帰と共通のハイパーパラメータ
    batch_size = 10
    max_epoch = 10000
    learning_rate = 1e-3
    momentum = 0.0
    regularize_coeff = 0.0

    # ニューラルネットワーク特有のハイパーパラメータ
    # 中間層のユニット数(チャンネル数)
    # NOTE: ここでは1層のみとしていますが、
    #       リストに値を付け加えていくことで層を追加できます
    #       ただし、メモリの使用量には気を付けてくださいね！
    num_units = [
        50,
        100,
    ]

    # 全データの取得
    data_train, (X_test, Y_test) = get_all(
        dimension, nonlinear, num_of_samples, noise_amplitude,
        return_coefficient_matrix=False
    )

    # 損失の履歴
    train_losses = []
    test_losses = []
    # パラメータの初期値
    W_hat = init_weights(num_units, dimension)
    for epoch in range(max_epoch):
        print("epoch: {0}/{1}".format(epoch, max_epoch))
        # バッチ単位に分割
        data_train_batch = get_batch(data_train, batch_size)
        # 1エポック分学習
        train_loss, W_hat = train_epoch(
            data_train_batch,  W_hat,
            learning_rate, momentum, regularize_coeff
        )

        # 結果を履歴に格納
        train_losses.append(train_loss)

        # テストデータへのフィッティング
        Y_hat = forward(X_test, W_hat)[-1][:, 0]
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
        "num_units": num_units,
    }
    # 結果の表示
    visualize_result(
        "neural_network",
        X_test[:, 0:2], Y_test, Y_hat, parameters,
        losses=(train_losses, test_losses)
    )


if __name__ == "__main__":
    main()
