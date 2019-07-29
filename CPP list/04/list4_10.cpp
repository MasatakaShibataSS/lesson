#include <iostream>
using namespace std;

void disp(int a, int b=200, int c=300);

int main()
{
    disp(111);
    disp(111, 222);
    disp(111, 222, 333);
    //dsip();		// ERROR aは必須引数
}

void disp(int a, int b, int c)
{
    cout << "a=" << a << " b=" << b << " c=" << c << '\n';
}
 
