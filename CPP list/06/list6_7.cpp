#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
	static int count;
public:
	Person();
	Person(string s, int n);
	~Person();
	void disp();
	static void dispCount();
};

// 静的データメンバ count の定義
int Person::count = 0;

// 引数なしのPersonクラスのコンストラクタ
Person::Person()
{
	++count;
	name = ""; age = 0;
}

// nameとageの引数を持つPersonクラスのコンストラクタ
Person::Person(string s, int n)
{
	++count;							// オブジェクトを作成するとcountを+1する
	name = s;
	if (n < 0) age = 0; else age = n;
}

// Personクラスのデストラクタ
Person::~Person()
{
	--count;							// オブジェクトを削除するとcountを-1する
}

// メンバー関数 disp の本体
void Person::disp()
{

	cout << "名前=" << name << "　年齢=" << age << '\n';
}

// 静的データメンバーを使って現在のオブジェクト数を表示する
void Person::dispCount()
{
	cout << "現在 " << count << "　個のPersonオブジェクトが有効" << '\n';
}

// Personクラスのオブジェクト cを宣言しdispCount関数でオブジェクト数を表示する
void func()
{
	Person x("関数太郎", 33);
	x.disp();
	Person::dispCount();
}

int main()
{
	Person::dispCount();		// クラス名を使った静的メンバー関数の呼び出し

	Person a("鈴木一郎", 11);	// Personクラスのオブジェクトaを宣言
	Person b("鈴木二郎", 22);	// Personクラスのオブジェクトbを宣言

	a.disp();
	b.disp();
	a.dispCount();				// オブジェクトaを使った静的メンバー関数の呼び出し
	b.dispCount();				// オブジェクトbを使った静的メンバー関数の呼び出し
	Person::dispCount();		// クラス名を使った静的メンバー関数の呼び出し

	func();

	Person::dispCount();		// クラス名を使った静的メンバー関数の呼び出し

	return 0;
}
