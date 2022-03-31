#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T, n, m, k;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        cin >> n;

        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            cin >> m;
            int sum = 0;
            for (int j = 0; j < m; ++j) {
                cin >> k;
                sum += k;
            }
            nums.push_back(sum);
        }
        sort(nums.begin(), nums.end());

        ll so_far = 0;
        ll sum = 0;
        for (auto n : nums) {
            so_far += n;
            sum += so_far;
        }

        cout << fixed << setprecision(10) << (double)sum / (double)nums.size() << endl;
    }
}
