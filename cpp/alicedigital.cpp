#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        vector<int> count_l(n, 0);
        vector<int> count_r(n, 0);

        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > m) {
                curr += nums[i];
            } else {
                if (nums[i] == m) {
                    count_l[i] = curr;
                }
                curr = 0;
            }
        }

        curr = 0;
        for (int i = n-1; i >= 0; --i) {
            if (nums[i] > m) {
                curr += nums[i];
            } else {
                if (nums[i] == m) {
                    count_r[i] = curr;
                }
                curr = 0;
            }
        }

        int highest = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == m) {
                int sum = count_l[i] + count_r[i] + m;
                highest = max(highest, sum);
            }
        }

        cout << highest << endl;
    }
}