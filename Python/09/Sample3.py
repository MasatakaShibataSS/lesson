word0 = input("１つめの単語を入力してください")
word1 = input("２つめの単語を入力してください")
word2 = input("３つめの単語を入力してください")

print("{0}は{1}{2}です。{2}です。".format(word0, word1, word2))

num0 = int(input("個数を入力してください"))
num1 = int(input("個金額を入力してください"))


print("{0:<}個{1:>10,}円".format(num0, num1))
