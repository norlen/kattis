#include <iostream>

using namespace std;

int main() {
    while (true) {
        int t, a, b;
        cin >> t;
        if (t == -1) break;

        int total = 0;
        int prev = 0;
        for (int i = 0; i < t; ++i) {
            cin >> a >> b;
            total += a * (b - prev);
            prev = b;
        }
        cout << total << " miles\n";
    }
}