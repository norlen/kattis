#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n;

    vector<string> names(n);
    unordered_map<string, vector<int>> m;
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        cin >> w;
        for (int j = 0; j < w; ++j) {
            string t;
            cin >> t;
            if (m.count(t) == 0) {
                m.insert({t, vector<int>()});
            }
            m[t].push_back(i);
        }
    }

    vector<int> counts(n, 0);
    int highest_count = 0;
    string t;
    while (cin >> t) {
        if (m.count(t) > 0) {
            for (auto c : m[t]) {
                counts[c]++;
                highest_count = max(highest_count, counts[c]);
            }
        }
    }

    vector<string> out;
    for (int i = 0; i < n; ++i) {
        if (counts[i] == highest_count) {
            out.push_back(names[i]);
        }
    }
    sort(out.begin(), out.end());

    for (int i = 0; i < out.size(); ++i) {
        cout << out[i] << endl;
    }
}
