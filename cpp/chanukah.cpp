#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int j, days;
        cin >> j >> days;
        int candles = (days + 1) * days / 2 + days;
        cout << j << " " << candles << endl;
    }
}