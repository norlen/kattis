#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool twosum(const vector<int>& nums) {
    unordered_set<int> s;
    int target = 7777;
    for (auto n : nums) {
        if (s.count(n)) return true;
        int rem = target - n;
        s.insert(rem);
    }
    return false;
}

bool has_dup(const vector<int>& nums) {
    unordered_set<int> s;
    for (auto n : nums) {
        if (s.count(n)) return true;
        s.insert(n);
    }
    return false;
}

int three(const vector<int>& nums) {
    unordered_map<int, int> ncount;
    for (auto n : nums) {
        ncount[n]++;
    }
    int times = nums.size() / 2;
    for (auto kv : ncount) {
        if (kv.second > times) {
            return kv.first;
        }
    }
    // cout << -1 << endl;
    return -1;
}

void four(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if (nums.size() % 2 == 1) {
        cout << nums[nums.size()/2] << endl;
    } else {
        int med = nums.size()/2;
        cout << nums[med-1] << " " << nums[med] << endl;
    }
}

void five(const vector<int>& nums) {
    vector<int> ans;
    for (auto n : nums) {
        if (n >= 100 && n <= 999) {
            ans.push_back(n);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto n : ans) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    switch (t) {
        case 1: {
            if (twosum(nums)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            break;
        }
        case 2: {
            if (has_dup(nums)) {
                cout << "Contains duplicate\n";
            } else {
                cout << "Unique\n";
            }
            break;
        }
        case 3: {
            int ans = three(nums);
            cout << ans << endl;
            break;
        }
        case 4: {
            four(nums);
            break;
        }
        case 5: {
            five(nums);
            break;
        }
    }
}
