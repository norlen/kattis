#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    double c, x, m;
    cin >> c >> x >> m;
    c /= 2.0;

    vector<pair<int, double>> speeds(6);
    for (int i = 0; i < 6; ++i) {
        cin >> speeds[i].first >> speeds[i].second;
    }

    int ok_speed = -1;
    for (int i = speeds.size()-1; i >= 0; --i) {
        double v = speeds[i].first;
        double mpg = speeds[i].second;

        double t = m / v;
        double leaked = t * x;
        double taken = m / mpg;
        double total = leaked + taken;
        // cout << "v=" << v << ", mpg=" << mpg << ", t=" << t << ", leaked=" << leaked << ", taken=" << taken << ", total=" << total << endl;
        if (total < c) {
            ok_speed = speeds[i].first;
            break;
        }
    }

    if (ok_speed == -1) {
        cout << "NO\n";
    } else {
        cout << "YES " << ok_speed << endl;
    }
}
