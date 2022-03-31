#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }
    vector<vector<int>> adds(n);
    for (int i = 0; i < n; ++i) {
        adds[i].push_back(i);
    }

    int last_idx = 0;
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        last_idx = a-1;
        for (auto v : adds[b-1]) {
            adds[a-1].push_back(v);
        }
    }

    for (auto v : adds[last_idx]) {
        cout << strings[v];
    }
}
