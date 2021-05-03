#include <iostream>

using namespace std;

int main() {
    double a, b, t;
    for (int i = 0; i < 4; ++i) {
        cin >> t;
        a += t * 0.25;
    }
    for (int i = 0; i < 4; ++i) {
        cin >> t;
        b += t * 0.25;
    }
    if (a > b) {
        cout << "Gunnar\n";
    } else if (a == b) {
        cout << "Tie\n";
    } else {
        cout << "Emma\n";
    }
}