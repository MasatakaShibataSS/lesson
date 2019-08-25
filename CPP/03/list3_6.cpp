#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{

    string str1, str2, str3;            // stringオブジェクトの宣言
    string strc;
    char cc[80];                        // C形式文字配列の宣言

    str1 = "Hello ";                    // 文字列の代入
    str2 = "cpp.";
    str3 = str1 + str2;                 // 文字列の連結

    cout << "str1=" << str1 << '\n';    // 文字列の出力
    cout << "str2=" << str2 << '\n';
    cout << "str3=" << str3 << '\n';

    if(str1 == "Hello ")
        cout << str1 << "world." << '\n';

    strcpy(cc, "Good ");
    str1 = cc;
    strcpy(cc, "morning.");
    str2 = cc;
    str3 = str1 + str2;

    cout << "str1=" << str1 << '\n';
    cout << "str2=" << str2 << '\n';
    cout << "str3=" << str3 << '\n';

    strc = "CSytele_string";
    strcpy(cc, strc.c_str());
    cout << "strc=" << strc << " cc=" << cc << '\n';

    return 0;
//L3_6
}
 
