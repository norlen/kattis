#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        vector<bool> ok(n, false);
        for (int i = 1; i < n; ++i) {
            int diff = abs(nums[i] - nums[i-1]);
            if (diff > 0 && diff < n) {
                ok[diff] = true;
            }
        }

        bool jolly = true;
        for (int i = 1; i < n; ++i) {
            if (!ok[i]) {
                jolly = false;
                break;
            }
        }

        if (jolly) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }
}
