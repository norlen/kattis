#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, s, r;
    cin >> n >> s >> r;

    vector<int> dam(n, 0);
    vector<int> res(n, 0);
    for (int i = 0; i < s; ++i) {
        int t;
        cin >> t;
        dam[t-1] = 1;
    }
    for (int i = 0; i < r; ++i) {
        int t;
        cin >> t;
        res[t-1] = 1;
    }

    int ok = 0;
    for (int i = 0; i < n; ++i) {
        if (dam[i]) {
            if (i > 0 && res[i-1] > 0) {
                res[i-1]--;
                ok++;
            } else if (i < n-1 && res[i+1] > 0) {
                res[i+1]--;
                ok++;
            }
        } else {
            ok++;
        }
    }

    // cout << "ok=" << ok << endl;
    cout << n - ok << endl;
}

