#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    double ratio = (double)y / (double)x;
    for (int i = 0; i < n; ++i) {
        double a;
        cin >> a;

        cout << (int)round(ratio * a) << endl;
    }
}
