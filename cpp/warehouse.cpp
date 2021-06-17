#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int p;
    cin >> p;

    for (int t = 0; t < p; ++t) {
        int n, k;
        cin >> n;

        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s >> k;
            if (mp.count(s) == 0) mp.insert({s, 0});
            mp[s] += k;
        }

        vector<pair<int, string>> v;
        for (pair<string, int> m : mp) {
            v.push_back({m.second, m.first});
        }

        sort(v.begin(), v.end(), [](const pair<int, string>& lhs, const pair<int, string>& rhs) {
            if (lhs.first == rhs.first) {
                return lhs.second < rhs.second;
            }
            return lhs.first > rhs.first;
        });

        cout << v.size() << endl;
        for (pair<int, string>& i : v) {
            cout << i.second << " " << i.first << endl;
        }
    }
}