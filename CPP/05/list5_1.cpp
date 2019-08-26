#include <iostream>
using namespace std;

int main() {

    int dt;
    int& rf = dt;

    dt=10;
    cout << "dt= " << dt << '\n';
    cout << "rf= " << rf << '\n';

    rf = 20;
    cout << "dt= " << dt << '\n';
    cout << "rf= " << rf << '\n';

    return 0;
}
