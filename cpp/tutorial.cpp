#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fac(ll n) {
    // clamp to [0,14] 14! ~= 87 billion which is above the max of `m`.
    n = min(n, (ll)14);
    ll ans = 1;
    for (ll i = 1; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

ll c2n(ll n) {
    n = min(n, (ll)50);
    return ((ll)1 << n);
}

bool check_pow(ll m, ll n, ll pow) {
    ll ans = n;
    for (int i = 1; i < pow; ++i) {
        ans *= n;
        if (ans > m) {
            // cout << " a=" << ans << endl;
            return false;
        }
    }
    // cout << " a=" << ans << endl;
    return true;
}

void check_tle(ll m, ll n, ll t) {
    bool tle = false;
    switch (t) {
        case 1: {
            // cout << " a=" << fac(n) << endl;
            if (fac(n) > m) tle = true;
            break;
        }
        case 2: {
            // cout << " a=" << c2n(n) << endl;
            if (c2n(n) > m) tle = true;
            break;
        }
        case 3: {
            if (!check_pow(m, n, 4)) tle = true;
            break;
        }
        case 4: {
            if (!check_pow(m, n, 3)) tle = true;
            break;
        }
        case 5: {
            if (!check_pow(m, n, 2)) tle = true;
            break;
        }
        case 6: {
            ll a = ceil((double)n * log2f64(n));
            // cout << "a=" << a << ", ad=" << (double)n * log2f64(n) << endl;
            if (a > m) tle = true;
            break;
        }
        case 7: {
            // cout << " a=" << n << endl;
            if (n > m) tle = true;
            break;
        }
    }

    if (tle) {
        cout << "TLE\n";
    } else {
        cout << "AC\n";
    }
}

int main() {
    ll m, n, t;
    cin >> m >> n >> t;
    check_tle(m, n, t);

    // while (cin >> m) {
    //     cin >> n >> t;
    //     cout << "m=" << m << ", n=" << n << ", t=" << t << endl;
    //     check_tle(m, n, t);
    // }
}
