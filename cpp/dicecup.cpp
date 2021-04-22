#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int d0, d1;
    cin >> d0 >> d1;

    unordered_map<int, int> m;
    for (int i = 1; i <= d0; ++i) {
        for (int j = 1; j <= d1; ++j) {
            int s = i + j;
            if (m.count(s)) {
                m[s]++;
            } else {
                m.insert({s, 1});
            }
        }
    }

    vector<int> res;
    int max = 0;
    for (auto kv : m) {
        if (kv.second == max) {
            res.push_back(kv.first);
        } else if (kv.second > max) {
            res.clear();
            res.push_back(kv.first);
            max = kv.second;
        }
    }

    sort(res.begin(), res.end());
    for (const auto v : res) {
        cout << v << endl;
    }
}