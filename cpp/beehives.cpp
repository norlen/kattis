#include <iostream>
#include <vector>

using namespace std;

int main() {
    double d;
    int n;
    while (true) {
        cin >> d >> n;
        if (d == 0.0 && n == 0) break;
        double dsq = d * d;

        vector<pair<double,double>> pos(n);
        vector<bool> ok(n);
        for (int i = 0; i < n; ++i) {
            cin >> pos[i].first >> pos[i].second;
            ok[i] = true;
        }

        // n is small (<= 100) so just brute force, O(n^2).
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                double dx = pos[i].first - pos[j].first;
                double dy = pos[i].second - pos[j].second;
                double distsq = dx*dx + dy*dy;
                ok[i] = ok[i] && distsq > dsq;
                ok[j] = ok[j] && distsq > dsq;
            }
        }

        int sour = 0, sweet = 0;
        for (int i = 0; i < n; ++i) {
            if (ok[i]) {
                sweet++;
            } else {
                sour++;
            }
        }

        cout << sour << " sour, " << sweet << " sweet\n";
    }
}