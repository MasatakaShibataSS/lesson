#include <iostream>
using namespace std;

void arydisp(int n[], int len);

int main()
{
    int dt[5] = {10, 20, 30, 40, 50};
    arydisp(dt, 5);
    return 0;
}

void arydisp(int name[], int len)
{
    int i;
    for (i=0; i<len; i++)
        cout << name[i] << '\n';
}
