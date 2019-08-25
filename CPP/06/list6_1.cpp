#include <iostream>
#include <string>
using namespace std;


class Person{
public:
	string name;
	int age;
	void disp();
};

void Person::disp()
{
		cout << "名前＝" << name << "　年齢" << age <<'\n';
}

int main()
{
	Person dt;

	dt.name = "鈴木一郎";
	dt.age = 30;
	dt.disp();
	
	return 0;
}
