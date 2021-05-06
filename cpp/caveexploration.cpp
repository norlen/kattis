#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int id = 0;

void dfs(vector<vector<int>>& edges, vector<int>& ids, vector<int>& low, vector<bool>& visited, set<pair<int,int>>& bridges, int u, int p) {
    visited[u] = true;
    id++;
    low[u] = id;
    ids[u] = id;

    for (auto v : edges[u]) {
        if (v == p) continue; // skip parent edge
        if (!visited[v]) {
            dfs(edges, ids, low, visited, bridges, v, u);
            low[u] = min(low[u], low[v]);
            if (ids[u] < low[v]) {
                bridges.insert({u, v});
            }
        } else {
            low[u] = min(low[u], low[v]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> ids(n);
    vector<int> low(n);
    vector<bool> visited(n);

    set<pair<int,int>> bridges;

    // find all bridges, we don't need to find components other than the one
    // connected to the starting node.
    if (!visited[0]) {
        dfs(edges, ids, low, visited, bridges, 0, -1);
    }

    // dfs from starting node, and skip bridges.
    visited = vector<bool>(n);
    stack<int> s;
    int count = 0;
    s.push(0);
    visited[0] = true;
    while (!s.empty()) {
        auto u = s.top();
        s.pop();
        count++;

        for (auto v : edges[u]) {
            bool is_bridge = bridges.count({u, v}) || bridges.count({v, u});
            if (visited[v] || is_bridge) continue;
            s.push(v);
            visited[v] = true;
        }
    }
    cout << count << endl;
}