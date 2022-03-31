#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int highest_dist = 0;
    for (int i = 0; i < n; ++i) {
        int d = p*(i+1);
        highest_dist = max(highest_dist, d - nums[i] + nums[0]);
    }

    cout << highest_dist << endl;
}
