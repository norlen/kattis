#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int count_ones(ll n) {
    int count = 0;
    for (ll i = 0; i < 31; ++i) {
        int mask = 1 << i;
        if ((n & mask) > 0) {
            count += 1;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;

        int max_count = 0;
        while (m > 0) {
            max_count = max(max_count, count_ones(m));
            m /= 10;
        }
        cout << max_count << endl;
    }
}
