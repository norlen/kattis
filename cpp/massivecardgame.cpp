#include <iostream>
#include <vector>
#include <map>

using namespace std;

int bsearch(vector<pair<int,int>>& nums, int needle, bool ret_prev) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int m = (high - low) / 2 + low;
        if (nums[m].first == needle) {
            if (ret_prev) {
                if (m == 0) return 0;
                return nums[m-1].second;
            }
            return nums[m].second;
        } else if (nums[m].first < needle) {
            low = m + 1;
        } else {
            high = m - 1;
        }
    }
    if (low == 0) return 0;
    return nums[low-1].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;

    map<int,int> m;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (m.count(t) == 0) {
            m.insert({t, 1});
        } else {
            m[t]++;
        }
    };

    vector<pair<int,int>> nums;
    int current_count = 0;
    for (auto kv : m) {
        current_count += kv.second;
        nums.push_back({kv.first, current_count});
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        int l = bsearch(nums, a, true);
        int h = bsearch(nums, b, false);
        cout << h - l << endl;
    }
}
