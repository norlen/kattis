#include <iostream>

using namespace std;

int main() {
    int t, a, b, c;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> a >> b >> c;
        if (a + b == c ||
            a - b == c ||
            a * b == c ||
            (a / b == c && a % b == 0) ||
            b - a == c ||
            (b / a == c && b % a == 0)) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }
}