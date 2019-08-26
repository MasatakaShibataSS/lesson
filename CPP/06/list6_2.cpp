#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    void setname(string s);
    void setage(int n);
    void disp();
};

void Person::setname(string s)
{
    name = s;
}

<<<<<<< HEAD

=======
>>>>>>> ea5a29cf095308bb6f3f8f4938f421db82c13a38
void Person::setage(int n)
{
    if (n < 0) age = 0; else age = n;
}

void Person::disp()
{
    cout << "名前＝" << name << "　年齢＝" << age << '\n';
}

int main()
{
    Person dt;

    dt.setname("鈴木一郎");
    dt.setage(-10);
    dt.disp();

    return 0;
}
<<<<<<< HEAD
=======
 
>>>>>>> ea5a29cf095308bb6f3f8f4938f421db82c13a38
