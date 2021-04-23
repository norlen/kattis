#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> dijsktras(int num_nodes, int source, vector<vector<pair<int,int>>>& edges) {
    auto d = vector<int>(num_nodes, INT32_MAX);
    set<pair<int,int>> s;

    d[source] = 0;
    s.insert({0, source});

    while (!s.empty()) {
        auto min_node = *s.begin();
        s.erase(s.begin());

        for (int i = 0; i < edges[min_node.second].size(); ++i) {
            auto p = edges[min_node.second][i];
            auto v = p.first;
            auto w = p.second;

            if (d[v] > d[min_node.second] + w) {
                if (d[v] != INT32_MAX) s.erase(s.find({d[v], v}));
                d[v] = d[min_node.second] + w;
                s.insert({d[v], v});
            }
        }
    }
    
    return d;
}

int main() {
    // n: nodes, m: edges, q: queries, s: start index
    while (true) {
        int n, m, q, s;
        cin >> n >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0) break;

        auto adj = vector<vector<pair<int,int>>>(n);
        // edges
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        auto d = dijsktras(n, s, adj);

        // queries
        for (int i = 0; i < q; ++i) {
            int v;
            cin >> v;
            if (d[v] == INT32_MAX) {
                cout << "Impossible" << endl;
            } else {
                cout << d[v] << endl;
            }
        }
    }
}