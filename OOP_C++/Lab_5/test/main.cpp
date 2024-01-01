#include <iostream>
using namespace std;

class Test {
    int x;

public:
    Test() {
        x = 0;
    }

    Test(int y) {
        x = y++;
    }

    Test(const Test &r) {
        x = r.x;
    }

    void print() {
        cout << x << endl;
    }
};

int main() {
    Test t(1);
    t.print();

    Test x(t);
    x.print();

    t.print();

    return 0;
}
