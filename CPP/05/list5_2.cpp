#include <iostream>
using namespace std;

void func_r(int& a) {
    a *= 2;
}

int main() {

    int dt;
    int& rf = dt;

    dt=10;
    cout << "dt= " << dt << '\n';
    cout << "rf= " << rf << '\n';

    func_r(rf);
    cout << "dt= " << dt << '\n';
    cout << "rf= " << rf << '\n';

    return 0;
}
 
