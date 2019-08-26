#include <iostream>
#include <string>
using namespace std;

class StrNum {
private:
	string str;
	int num;
public:
	void set(string s, int n);
	void disp();
};
// メンバー関数 set の本体
void StrNum::set(string s, int n) {
	str = s; num = n;
}
// メンバー関数 dispの本体
void StrNum::disp()
{
	cout << "str=" << str << " num=" << num << '\n';
}

// StrNumオブジェクトを戻り値と引数（値渡し)にする関数
StrNum fnc_v(StrNum dt)
{
	cout << "現在の内容："; dt.disp();
	dt.set("fnc_v設定文字列", 10);
	return dt;
}

// StrNumオブジェクトのポインタを引数にする関数
void fnc_p(StrNum* dt)
{
	cout << "現在の内容："; dt -> disp();
	dt-> set("fnc_p設定文字列", 20);
}

// StrNumオブジェクトの参照を引数にする関数
void fnc_r(StrNum& dt)
{
	cout << "現在の内容：" ; dt.disp();
	dt.set("fnc_r設定文字列", 30);
}

int main()
{
	StrNum a;				// StrNumのオブジェクトaを宣言

	a.set("TEST1", 0);
	a = fnc_v(a);			// aを引数にして関数呼び出し(値渡し)、戻り値はオブジェクト
	a.disp();

	a.set("TEST2", 0);
	fnc_p(&a);				// aのポインタを引数にして関数呼び出し
	a.disp();

	a.set("TEST3", 0);
	fnc_r(a);				// aの参照を引数にして関数呼び出し
	a.disp();

	return 0;
}
 
