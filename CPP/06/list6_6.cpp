#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
    Person(){name = ""; age = 0; }
    Person(string s, int n){
        name = s;
        n < 0  ? age = 0: age = n;
    }
    void setname(string s) { name = s; }
    void setage(int n) { n < 0 ? age = 0 : age = n; }
    void disp(){
	cout << "名前=" << name << "　年齢=" << age << '\n';
    }
};


int main()
{

    Person dt1("鈴木一郎", 51);
    Person dt2;

    dt2.setname("佐藤太郎");
    dt2.setage(40);
    dt1.disp();
    dt2.disp();

    return 0;
}
