#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int ans = 0;
    int i = 0;
    int j = v.size() - 1;
    while (i <= j) {
        int s = v[i] + v[j];
        // cout << "i=" << i << ", j=" << j << ", v[i]="<< v[i] << ", v[j]=" << v[j] << " s<=x=" << (s<=x) << endl;
        if (s <= x) {
            ans++;
            ++i;
        } else if (i==j && i > 0) {
            ans++;
            --j;
        } else {
            --j;
        }
    }

    if (v.size() == 1) {
        ans = 1;
    }

    cout << ans << endl;
}
