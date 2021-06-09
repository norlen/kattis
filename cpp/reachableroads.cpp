#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int m, r;
        cin >> m >> r;

        // Initialize edges and visited.
        vector<vector<int>> edges(m);
        vector<bool> visited(m);
        for (int j = 0; j < m; ++j) {
            edges[j] = vector<int>();
            visited[j] = false;
        }

        // Get all edges.
        for (int j = 0; j < r; ++j) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        // Find number of components using DFS.
        int components = 0;
        for (int j = 0; j < m; ++j) {
            if (visited[j] == true) continue;
            visited[j] = true;
            components++;

            stack<int> s;
            s.push(j);
            while (!s.empty()) {
                auto u = s.top();
                s.pop();

                for (auto v : edges[u]) {
                    if (visited[v]) continue;
                    visited[v] = true;
                    s.push(v);
                }
            }
        }

        // We have to add components-1 edges for all of them to be connected.
        // Let's be safe by having it be at least 0.
        cout << max(0, components - 1) << endl;
    }
}