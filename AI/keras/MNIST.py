import keras
from keras.datasets import mnist
from keras.models import Sequential
from keras.layers import Dense, Dropout
from keras.optimizers import RMSprop

batch_size = 128  # 訓練データを128ずつのデータに分けて学習させる
num_classes = 10 # 分類させる数。数字なので10種類
epochs = 10 # 訓練データを繰り返し学習させる数

# 訓練データ(train)とテストデータ（test)を取得する
(x_train, y_train), (x_test, y_test) = mnist.load_data()

# 元のデータは1次元の配列なので、それを画像毎の配列に整形する
x_train = x_train.reshape(60000, 784)
x_test = x_test.reshape(10000, 784)
x_train = x_train.astype('float32')
x_test = x_test.astype('float32')
x_train /= 255
x_test /= 255
print(x_train.shape[0], 'train samples')
print(x_test.shape[0], 'test samples')

# y(目的変数)には0から9の数字が入っているが、Kerasで扱いやすい形に変換する
y_train = keras.utils.to_categorical(y_train, num_classes)
y_test = keras.utils.to_categorical(y_test, num_classes)

# モデルの作成
model = Sequential()
model.add(Dense(512, activation='relu', input_shape=(784,)))
model.add(Dropout(0.2))
model.add(Dense(512, activation='relu'))
model.add(Dropout(0.2))
model.add(Dense(num_classes, activation='softmax'))

model.summary()

model.compile(loss='categorical_crossentropy',
 optimizer=RMSprop(),
 metrics=['accuracy'])

# 学習は、scrkit-learnと同様fitで記述できる
history = model.fit(x_train, y_train,
 batch_size=batch_size,
 epochs=epochs,
 verbose=1,
 validation_data=(x_test, y_test))

# 評価はevaluateで行う
score = model.evaluate(x_test, y_test, verbose=0)
print('Test loss:', score[0])
print('Test accuracy:', score[1])
