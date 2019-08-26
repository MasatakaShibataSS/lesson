#include <iostream>
using namespace std;

void putd(int d);    //関数プロトタイプ宣言

int main()
{
    putd(1234);
    return 0;
}

void putd(int dt)    //数値を出力する戻り値の無い関数
{
    cout << dt << '\n';
}
 
