#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<int> heads(n);
        vector<int> knights(m);
        for (int i = 0; i < n; ++i) {
            cin >> heads[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> knights[i];
        }

        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());
        int count = 0;
        int sum = 0;

        int i = 0;
        int j = 0;
        while (i < heads.size() && j < knights.size()) {
            // cout << "i=" << i << ", j=" << j << ", heads[i]=" << heads[i] << ", knights[j]=" << knights[j] << endl;
            if (knights[j] >= heads[i]) {
                count++;
                sum += knights[j];
                // cout << " ok! count=" << count << ", sum=" << sum << endl;
                ++i;
                ++j;
            } else {
                // cout << " not ok, next knight\n";
                ++j;
            }
        }

        if (count != heads.size()) {
            cout << "Loowater is doomed!\n";
        } else {
            cout << sum << endl;
        }
    }
}