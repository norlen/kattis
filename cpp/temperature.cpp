#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (x == 0 && y == 1.0) {
        cout << "ALL GOOD\n";
    } else if (x == 0) {
        cout << x << endl;
    } else if (abs(y) <= 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << setprecision(10) << (double)x/(1.0-(double)y) << endl;
    }
}