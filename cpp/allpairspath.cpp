#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    bool f = true;
    while (true) {
        int n, m, q;
        cin >> n >> m >> q;
        if (n == 0 && m == 0 && q == 0) break;
        if (!f) cout << endl;
        f = false;
        
        vector<vector<double>> dist(n, vector<double>(n, numeric_limits<double>::infinity()));
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = w;
        }

        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        // Floyd-Warshall APSP
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = ll(dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Detect negative cycles
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = -numeric_limits<double>::infinity();
                    }
                }
            }
        }

        // Queries.
        for (int i = 0; i < q; ++i) {
            int u, v;
            cin >> u >> v;

            if (dist[u][v] == -numeric_limits<double>::infinity()) {
                cout << "-Infinity\n";
            } else if (dist[u][v] == numeric_limits<double>::infinity()) {
                cout << "Impossible\n";
            } else {
                cout << ll(dist[u][v]) << endl;
            }
        }
    }
}