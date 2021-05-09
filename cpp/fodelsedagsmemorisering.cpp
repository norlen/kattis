#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, pair<string, int>> bdays;

    for (int i = 0; i < n; ++i) {
        string name;
        int c, m, d;
        char ch;
        cin >> name >> c >> d >> ch >> m;

        int idx = (m - 1) * 31 + (d - 1);
        if (bdays.count(idx) == 0 || c > bdays[idx].second) {
            bdays[idx] = { name, c};
        }
    }

    vector<pair<string, int>> out;
    out.reserve(bdays.size());
    for (auto& bb : bdays) {
        out.push_back(bb.second);
    }
    sort(out.begin(), out.end());

    cout << out.size() << endl;
    for (auto& bd : out) {
        cout << bd.first << endl;
    }
}