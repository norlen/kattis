#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int l, m;
        cin >> l >> m;
        int ferry = 0;
        l *= 100;

        deque<int> q[2];
        constexpr int LEFT = 0;
        constexpr int RIGHT = 1;
        for (int i = 0; i < m; ++i) {
            string dir;
            int len;
            cin >> len >> dir;
            if (dir == "left") {
                q[LEFT].push_back(len);
            } else {
                q[RIGHT].push_back(len);
            }
        }

        int trips = 0;
        while (true) {
            if (q[LEFT].size() == 0 && q[RIGHT].size() == 0) break;
            // cout << "trips=" << trips << " ql.s=" << q[LEFT].size() << ", qr.s=" << q[RIGHT].size() << endl;
            trips++;
            // this_thread::sleep_for(100ms);

            int cargo = 0;
            while (q[ferry].size() > 0) {
                int len = q[ferry].front();
                if (cargo + len > l) break;
                cargo += len;
                q[ferry].pop_front();
            }
            ferry = (ferry + 1) % 2;
            // cout << "cargo=" << cargo << endl;
        }
        cout << trips << endl;
    }
}
