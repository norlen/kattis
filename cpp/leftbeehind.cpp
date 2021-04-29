#include <iostream>

using namespace std;

int main() {
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;

        if (a + b == 13) {
            cout << "Never speak again.\n";
        } else if (a < b) {
            cout << "Left beehind.\n";
        } else if (a > b) {
            cout << "To the convention.\n";
        } else {
            cout << "Undecided.\n";
        }
    }
}