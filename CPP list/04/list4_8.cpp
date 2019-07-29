#include <iostream>
using namespace std;
void strout(char ss[]);


int main()
{
	char aa[] = "Hello";
	strout(aa);
	strout((char*)"world");
	return 0;
}
void strout(char ss[])
{
cout << "文字列表示：" << ss << '\n';
cout << "先頭文字は" << ss[0] << '\n';
}
