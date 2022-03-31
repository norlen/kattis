#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, t;
    cin >> n;

    int m = -1;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (m == -1) {
            m = t;
        } else {
            if (t % m == 0) {
                cout << t << endl;
                m = -1;
            }
        }
    }
}