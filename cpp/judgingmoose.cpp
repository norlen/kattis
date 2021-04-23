#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int m = max(x, y);
    if (x == 0 && y == 0) {
        cout << "Not a moose\n";
    } else {
        cout << ((x - y) != 0 ? "Odd " : "Even ") << 2*m << endl;
    }
}