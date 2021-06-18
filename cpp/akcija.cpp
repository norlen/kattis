#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    sort(p.rbegin(), p.rend());
    ll t = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 3 == 0) continue;
        t += p[i-1];
    }
    cout << t << endl;
}