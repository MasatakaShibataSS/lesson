#include <iostream>
using namespace std;

int maxdt(int a, int b);

int main()
{
	int m;

	m =maxdt(100,200);
	cout << "max=" << m << '\n';
	cout << "max=" << maxdt(50,20) << '\n';
	return 0;
}

int maxdt(int a, int b)
{
	if(a > b)
	return a;
	else
	return b;
}
