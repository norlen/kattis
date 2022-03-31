#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        ll p, r, f;
        cin >> p >> r >> f;

        ll years = 0;
        while (p <= f) {
            p = p * r;
            years++;
        }
        cout << years << endl;
    }
}
