#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;

    int low = -1, high;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (low == -1) {
            low = a;
            high = b;
        } else {
            low = max(low, a);
            high = min(high, b);
            if (high < low) {
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "gunilla has a point\n" : "edward is right\n");
}