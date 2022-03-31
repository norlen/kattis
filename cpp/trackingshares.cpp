#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int c;
    cin >> c;

    vector<vector<int>> comp(365, vector<int>(c, 0));
    for (int i = 0; i < c; ++i) {
        int k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            int n, d;
            cin >> n >> d;

            comp[d-1][i] = n;
        }
    }

    vector<int> curr(c, 0);
    for (int i = 0; i < 365; ++i) {
        bool display = false;
        for (int j = 0; j < c; ++j) {
            if (comp[i][j] > 0) {
                display = true;
                curr[j] = comp[i][j];
            }
        }

        if (display) {
            ll sum = accumulate(curr.begin(), curr.end(), 0);
            cout << sum << " ";
        }
    }
    cout << endl;
}