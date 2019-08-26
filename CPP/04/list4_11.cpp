#include <iostream>
using namespace std;

int maxdata(int a, int b);    //　関数プロトタイプ（関数型　仮引数型　仮引数名）
int maxdata(int a, int b, int c);
double maxdata(double a, double b);

int main()
{

    int n1, n2, n3, id1= 1111, id2= 2222;
    double db;

    n1 = maxdata(id1, id2);
    n2 = maxdata(3333, 4444);
    n3 = maxdata(3333, 4444, 5555);
    db = maxdata(55.55, 66.66);

    cout << "n1=" << n1 << '\n';
    cout << "n2=" << n2 << '\n';
    cout << "n3=" << n3 << '\n';
    cout << "db=" << db << '\n';

    return 0;
}

int maxdata(int a, int b)           // 実引数型
{
    if(a > b) return a; else return b;
}
int maxdata(int a, int b, int c)     // 実引数型
{
    if(a>b && a>c) return a;
    if(b > c) return b; else return c;
}

double maxdata(double a, double b)    // 実引数型
{
    if(a > b) return a; else return b;
}
 
