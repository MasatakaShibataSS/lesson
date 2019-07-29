#include <iostream>
using namespace std;

double triangle(double x, double y);    // 関数のプロトタイプ宣言

int main()
{
    double a, b, area;                  // 変数の宣言

    a = 10.5;
    b = 20.5;
    area = triangle(a, b);              // 関数で三角形の面積を求める
    cout << "a=" << a << " b=" << b << " area=" << area << '\n';

    return 0;
}

double triangle(double x, double y)
{

    return x*y/2;                       // 与えられたx,yから面積を戻り値として返す
}
 
