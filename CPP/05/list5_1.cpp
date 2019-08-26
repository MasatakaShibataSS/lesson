<<<<<<< HEAD
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
=======
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
>>>>>>> ea5a29cf095308bb6f3f8f4938f421db82c13a38
