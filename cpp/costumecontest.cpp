#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (mp.count(s) == 0) mp.insert({s, 0});
        mp[s] += 1;
    }

    int lowest = n;
    for (auto& m : mp) {
        lowest = min(lowest, m.second);
    }

    vector<string> low;
    for (auto& m : mp) {
        if (m.second == lowest) {
            low.push_back(m.first);
        }
    }
    sort(low.begin(), low.end());
    
    for (auto& s : low) {
        cout << s << endl;
    }
}