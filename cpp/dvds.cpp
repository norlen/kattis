#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;

        int curr = 0;
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;

            if (curr+1 == m) {
                curr++;
            }
        }
        // cout << curr << endl;
        cout << n - curr << endl;
    }
}
