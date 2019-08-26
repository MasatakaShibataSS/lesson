#include <iostream>
using namespace std;

class MyClass {
private:
	int idt;
public:
	MyClass(int n);
	~MyClass();
	void disp();
};

// MyClassのコンストラクタ
MyClass::MyClass(int n)
{
	idt = n;
	cout << "引数=" << n << "でコンストラクタが呼ばれました。" << '\n';
}

// MyClassのデストラクタ
MyClass::~MyClass()
{

	cout << "idt=" << idt << "のデストラクタが呼ばれました。" << '\n';
}
// MyClassのdisp関数本体
void MyClass::disp()
{
	cout << "disp:idt=" << idt << '\n';
}

void func()
{
	MyClass c(300);			// n=300でMyClassのオブジェクトcを宣言
							// ここでコンストラクタが呼ばれる
	c.disp();
}							// func()終了でcのデストラクタが呼ばれる

int main()
{
	int nn = 1;
	MyClass a(100);			// n=100でMyClassのオブジェクトaを宣言
							// ここでコンストラクタが呼ばれる
	a.disp();

	if (nn == 1) {
		MyClass b(200);		// n=200でMyClassのオブジェクトbを宣言
							// ここでコンストラクタが呼ばれる
		b.disp();
	}						// if文のブロック終了でbのデストラクタが呼ばれる

	func();					// 関数呼び出し

	return 0;				// main()終了でaのデストラクタが呼ばれる
}
 
