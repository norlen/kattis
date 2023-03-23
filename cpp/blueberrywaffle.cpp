#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    double r, f;
    cin >> r >> f;
    double deg_per_sec = 180 / r;
    double deg_at_stop = static_cast<int>(deg_per_sec * f) % 360;

    if (deg_at_stop <= 90 || deg_at_stop >= 270) {
        cout << "up\n";
    } else {
        cout << "down\n";
    }
}
