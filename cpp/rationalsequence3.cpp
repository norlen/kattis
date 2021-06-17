#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    int p;
    cin >> p;
    
    for (int i = 0; i < p; ++i) {
        ll k, n;
        cin >> k >> n;

        int nodes_this_level = (ll)pow(2.0, (ll)log2(n));
        int idx = n - nodes_this_level;

        // Check path this takes to root. True is right child.
        vector<bool> path;
        while (nodes_this_level > 1) {
            path.push_back(idx % 2 == 1);

            idx /= 2;
            nodes_this_level /= 2;
        }

        // Recreate from path.
        pair<int,int> ans = {1, 1};
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            if (*it) {
                ans = {ans.first + ans.second, ans.second};
            } else {
                ans = {ans.first, ans.first + ans.second};
            }
        }
        cout << k << " " << ans.first << "/" << ans.second << endl;
    }
}