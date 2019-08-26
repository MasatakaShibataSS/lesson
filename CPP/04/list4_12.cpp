#include <iostream>
using namespace std;

inline double circle_in(double r)       // インライン関数の定義
{
    return r*r*3.14159;
}

double circle(double r)                 // 通常の関数定義
{
    return r*r*3.14159;
}

int main()
{

    double a = 10.0, b=20.0;

    cout << "area1=" << circle_in(a) << '\n';   // インライン関数
    cout << "area2=" << circle(b) << '\n';      // 通常の関数

    return 0;
}
 
