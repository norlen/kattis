#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> sizes(n);
    for (int i = 0; i < n; ++i) {
        cin >> sizes[i];
    }
    sort(sizes.begin(), sizes.end());

    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        ll needs;
        cin >> needs;
        ll lb = *lower_bound(sizes.begin(), sizes.end(), needs);

        // cout << "needs=" << needs << ", lower_bound=" << lb << endl;
        ans += (lb - needs);
    }

    cout << ans << endl;
}
