#include <bits/stdc++.h>
using u8 = uint8_t;
using i8 = int8_t;
using u16 = uint16_t;
using i16 = int16_t;
using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using i64 = int64_t;

using namespace std;

double distance(pair<int,int> p0, pair<int,int> p1, int p0f, int p1f) {
    int dx = p0.first - p1.first;
    int dy = p0.second - p1.second;
    int dz = (p0f - p1f) * 5;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int,int>>> places(n);
    vector<vector<double>> dist(n, vector<double>(n, INFINITY));
    vector<vector<int>> p(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        p[i][i] = i;
    }

    // Target locations (floor, x, y).
    for (int i = 0; i < n; ++i) {
        int floor, x, y;
        cin >> floor >> x >> y;
        places[i] = {floor, {x, y}};
    }

    // Edges (x, y, type)
    for (int i = 0; i < m; ++i) {
        int u, v;
        string t;
        cin >> u >> v >> t;
        auto p0 = places[u];
        auto p1 = places[v];
        if (t == "walking" || t == "stairs") {
            double cost = distance(p0.second, p1.second, p0.first, p1.first);
            dist[u][v] = cost;
            dist[v][u] = cost;
        } else if (t == "lift") {
            dist[u][v] = 1;
            dist[v][u] = 1;
        } else if (t == "escalator") {
            double cost = distance(p0.second, p1.second, p0.first, p1.first);
            dist[u][v] = 1;
            dist[v][u] = cost * 3;
        }
        p[u][v] = v;
        p[v][u] = u;
    }

    // Floyd-warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    p[i][j] = p[i][k];
                }
            }
        }
    }

    // Queries.
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << u << " ";
        while (u != v) {
            u = p[u][v];
            cout << u << " ";
        }
        cout << endl;
    }
}
