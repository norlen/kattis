#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    sort(t.rbegin(), t.rend());
    
    ll ans = 0;
    for (int i = 0; i < t.size(); ++i) {
        ll d = t[i] + i + 2;
        ans = max(ans, d);
    }
    cout << ans << endl;
}