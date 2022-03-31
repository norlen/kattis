#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int g, t, n, v;
    cin >> g >> t >> n;

    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        s += v;
    }
    int w = (g - t) * 9 / 10;

    cout << (w - s) << endl;
}
