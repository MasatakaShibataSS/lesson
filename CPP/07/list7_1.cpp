<<<<<<< HEAD

#include <iostream>
using namespace std;

// ---------基底クラス---------
class Foo {
private:
 int x;
public:
 Foo()				{ x = 0; }
 Foo(int n)			{ x = n; }
 void setX(int n)	{ x = n; }
 int getX()			{ return x; }
 void dispFoo()		{ cout << "x=" << x << '\n'; }
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
 void dispBar();
};

Bar::Bar()
{
 setX(0);
 y = 0;
}

Bar::Bar(int n1, int n2)
{
 setX(n1);
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

void Bar::dispBar()
{
 dispFoo();
 cout << "y=" << y << '\n';
}

int main()
{
 Bar bar(10, 20);

 cout << "------Barの確認\n";
 bar.dispFoo();
 bar.dispBar();

 cout << "------setX,setYを使う\n";
 bar.setX(100);
 bar.setY(200);
 bar.dispBar();
 cout << "------getX,getYを使う\n";
 cout << "bar.x=" << bar.getX() << '\n';
 cout << "bar.y=" << bar.getY() << '\n';

 return 0;
}
=======
#include <iostream>
using namespace std;

int main()
{

	return 0;
}

>>>>>>> ea5a29cf095308bb6f3f8f4938f421db82c13a38
