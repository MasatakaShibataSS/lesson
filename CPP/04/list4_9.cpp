#include <iostream>
using namespace std;

void strout(char *ss);
void dtout(int *a);

int main()
{
    char aa[] = "Hello";
    strout(aa);

    int a= 100;
    dtout(&a);

    return 0;
}

void strout(char *ss)
{
    cout << "文字列表示：" << ss << '\n';
    cout << "先頭文字は" << ss[0] << '\n';
}
void dtout(int *x)
{
    cout << "data = " << *x << '\n';
}
