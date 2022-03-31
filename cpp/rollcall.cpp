#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string first, last;

    unordered_map<string, int> fname_count;
    map<string, vector<string>> lname;
    while (cin >> first) {
        cin >> last;

        fname_count[first]++;
        lname[last].push_back(first);
    }

    for (auto kv : lname) {
        sort(kv.second.begin(), kv.second.end());
        for (auto fname : kv.second) {
            if (fname_count[fname] > 1) {
                cout << fname << " " << kv.first << endl;
            } else {
                cout << fname << endl;
            }
        }
    }
}
