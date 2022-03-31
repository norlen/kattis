#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        ll cs, ec;
        cin >> cs >> ec;
    
        ll cs_sum = 0;
        ll ec_sum = 0;
        vector<ll> css(cs);
        vector<ll> ecs(ec);
        for (ll i = 0; i < cs; ++i) {
            cin >> css[i];
            cs_sum += css[i];
        }
        for (ll i = 0; i < ec; ++i) {
            cin >> ecs[i];
            ec_sum += ecs[i];
        }
        sort(css.begin(), css.end());
        sort(ecs.begin(), ecs.end());

        double cs_avg = (double)cs_sum / (double)cs;
        double ec_avg = (double)ec_sum / (double)ec;

        // cout << "cs=" << cs_avg << ", ec=" << ec_avg << endl;

        ll count = 0;
        for (ll i = 0; i < cs; ++i) {
            double iq = css[i];
            if (iq > ec_avg && iq < cs_avg) {
                count++;
            }
        }
        cout << count << endl;
    }
}
