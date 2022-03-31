#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, m, l;
        cin >> n >> m >> l;

        vector<vector<int>> edges(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            edges[u-1].push_back(v-1);
        }

        ll count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < l; ++i) {
            int start;
            cin >> start;
            start -= 1;
            if (visited[start]) continue;

            deque<int> q;
            q.push_back(start);
            visited[start] = true;

            while (!q.empty()) {
                auto u = q.front();
                q.pop_front();
                count += 1;

                for (auto v : edges[u]) {
                    if (visited[v]) continue;
                    visited[v] = true;
                    q.push_back(v);
                }
            }
        }

        cout << count << endl;
    }
}