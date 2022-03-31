#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, c;
    cin >> n >> c;

    int max_freq = 0;
    unordered_map<int, pair<int,int>> freq;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        if (freq.count(v) == 0) {
            freq[v] = {i, 0};
        }
        freq[v].second++;
        max_freq = max(max_freq, freq[v].second);
    }

    vector<pair<int,pair<int,int>>> ans;
    for (auto kv : freq) {
        ans.push_back({max_freq - kv.second.second, {kv.second.first, kv.first}});
    }
    sort(ans.begin(), ans.end());

    for (auto a : ans) {
        for (int i = 0; i < (max_freq - a.first); ++i) {
            cout << a.second.second << " ";
        }
    }
    cout << endl;
}
