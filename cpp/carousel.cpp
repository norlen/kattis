#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        int num_tickets, b;
        double best_value = INFINITY;
        int t, p;
        for (int i = 0; i < n; ++i) {
            cin >> num_tickets >> b;

            // a tickets for $b
            // require to buy more than m tickets
            if (num_tickets > m) continue;

            double z = double(b) / double(num_tickets);
            if (z < best_value || (z == best_value && num_tickets > t)) {
                best_value = z;
                t = num_tickets;
                p = b;
            }
        }

        if (best_value != INFINITY) {
            cout << "Buy " << t << " tickets for $" << p << endl;
        } else {
            cout << "No suitable tickets offered\n";
        }
    }
}
