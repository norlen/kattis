#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool is_ok(int n, int k) {
    if (k < n) return false;

    vector<bool> on(n+1, false);

    int req = 0;
    while (on[n] == false) {
        req++;
        bool power = true;
        for (int i = 0; i < n+1; ++i) {
            if (power == false) break;
            power = on[i];
            on[i] = !on[i];
            if (power == false) break;
        }

        // cout << "Status=";
        // for (auto v : on) {
        //     cout << v << " ";
        // }
        // cout << endl;
    }
    int clicks_req = req - 1;
    // cout << "Clicks required=" << clicks_req << endl;

    if (k == clicks_req) return true;
    return (k-clicks_req) % req == 0;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, k;
        cin >> n >> k;


        bool on = is_ok(n, k);
        cout << "Case #" << t+1 << ": ";
        if (on) {
            cout << "ON\n";
        } else {
            cout << "OFF\n";
        }
    }
}
