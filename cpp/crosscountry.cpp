#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, s, t;
    cin >> n >> s >> t;

    vector<vector<int>> e(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> e[i][j];
        }
    }

    vector<int> ds(n, INT32_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});
    ds[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (u == t) {
            cout << cost << endl;
            return 0;
        }

        for (int j = 0; j < n; ++j) {
            if (e[u][j] == 0) continue;
            int d = cost + e[u][j];
            // cout << "u=" << u << ", v=" << j << ", d=" << d << ", ds[v]=" << ds[j] << endl;
            if (d < ds[j]) {
                ds[j] = d;
                pq.push({d, j});
            }
        }
    }
}