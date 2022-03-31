#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    bool first = true;
    while (true) {
        int n, m, q, s;
        cin >> n >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0) break;
        if (!first) cout << endl;
        first = false;

        vector<pair<pair<int,int>, int>> edges;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({{u, v}, w});
        }

        vector<double> dist(n, numeric_limits<double>::infinity());
        dist[s] = 0;

        // Bellman-Ford
        for (int i = 0; i < n-1; ++i) {
            for (auto e : edges) {
                int u = e.first.first;
                int v = e.first.second;
                double w = e.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Detect negative cycles.
        for(int i = 0; i < n-1; ++i) {
            for (auto e : edges) {
                int u = e.first.first;
                int v = e.first.second;
                double w = e.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = -numeric_limits<double>::infinity();
                }
            }
        }

        // Queries.
        for (int i = 0; i < q; ++i) {
            int t;
            cin >> t;

            if (dist[t] == -numeric_limits<double>::infinity()) {
                cout << "-Infinity\n";
            } else if (dist[t] == numeric_limits<double>::infinity()) {
                cout << "Impossible\n";
            } else {
                cout << dist[t] << endl;
            }
        }
    }
}