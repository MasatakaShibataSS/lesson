#include <iostream>
using namespace std;

<<<<<<< HEAD
// ---------基底クラス---------
class Foo {
private:
    int x;
public:
    Foo()            { x = 0; }
    Foo(int n)        { x = n; }
    void setX(int n)    { x = n; }
    int getX()        { return x; }
    void disp()        { cout << "x=" << x << '\n'; }
};

//----------派生クラス---------
class Bar : public Foo {
private:
    int y;
public:
    Bar();
    Bar(int n1, int n2);
    void setY(int n);
    int getY();
    void disp();
};

Bar::Bar(): Foo(0)
{
    y = 0;
}

Bar::Bar(int n1, int n2) : Foo(n1)
{
    y = n2;
}

void Bar::setY(int n)
{
    y = n;
}

int Bar::getY()
{
    return y;
}

void Bar::disp()
{
    Foo::disp();
    cout << "y=" << y << '\n';
}

int main()
{
    Foo foo(10);
    Bar bar(20, 30);

    cout << "------Fooの確認\n";
    foo.disp();

    cout << "------Barの確認\n";
    bar.disp();

    return 0;
}
=======
int main()
{

	return 0;
}

>>>>>>> ea5a29cf095308bb6f3f8f4938f421db82c13a38
