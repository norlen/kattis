#include <iostream>

using namespace std;

int main() {
    int b, c = 1, h = 0;
    cin >> b;
    while (b >= c*c) {
        b -= c*c;
        c += 2;
        h += 1;
    }
    cout << h << endl;
}
