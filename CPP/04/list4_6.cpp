#include <iostream>
#include <string>
using namespace std;

void disp_str(string s);
string add_paren(string s);

int main()
{
	string ss ="hello", ss2;

	disp_str(ss);
	disp_str("world");

	ss2 = add_paren(ss);
	cout << "ss2=" << ss2 << '\n';

	return 0;
}

void disp_str(string s)
{
    cout << s << '\n';
}


string add_paren(string s){
	string wkss;
	wkss = "(" + s + ")";
	return wkss;
}
