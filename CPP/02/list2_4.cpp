#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;

    while(getline(cin, str)){       // strに文字列を入力、Ctl+dで入力終了
        cout << "[" << str <<"]\n";     // 入力された文字列を出力
    }
    return 0;
}
 
