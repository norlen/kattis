#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    vector<int> nums;
    while (true) {
        int t, both = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        nums.clear();
        if (nums.capacity() < n) {
            nums.resize(n);
        }

        for (int i = 0; i < n; ++i) cin >> nums[i];

        int i = 0;
        for (int j = 0; j < m; ++j) {
            cin >> t;
            while (nums[i] < t && i < n-1) ++i;
            if (nums[i] == t) both++;
        }
        cout << both << endl;
    }
}

// Alternative solution:
// unordered_set<int> s;
// for (int i = 0; i < n; ++i) {
//     cin >> t;
//     s.insert(t);
// }
// for (int i = 0; i < m; ++i) {
//     cin >> t;
//     if (s.count(t) > 0) {
//         both++;
//     }
// }