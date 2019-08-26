#include <iostream>
using namespace std;

double average(double x, double y);

int main()
{
	double a = 11.11;
	double b = 33.33;
	double ave = average(a, b);
	cout << ave << '\n';

	return 0;
}

double average(double x, double y)
{
	double z;
	z = (x+y)/2.0;
	return z;
}
