#include <bits/stdc++.h>

using namespace std;
using ll = long long;

unordered_map<string, vector<string>> edges;
unordered_map<string, vector<string>> edges_rev;
unordered_set<string> visited;

vector<string> seen;

int num_components = 0;
unordered_map<string, int> component;
unordered_map<int, vector<string>> components;

void dfs(const string& u) {
    visited.insert(u);

    for (const string& v : edges[u]) {
        if (visited.count(v)) continue;
        dfs(v);
    }
    seen.push_back(u);
}

void dfs_rev(const string& u) {
    visited.insert(u);
    component[u] = num_components;
    components[num_components].push_back(u);

    for (const string& v : edges_rev[u]) {
        if (visited.count(v)) continue;
        dfs_rev(v);
    }
}

int main() {
    int n;
    cin >> n;

    // Run Kosarajus.
    unordered_set<string> nodes;
    for (int i = 0; i < n; ++i) {
        string u, v;
        cin >> u >> v;

        nodes.insert(u);
        nodes.insert(v);

        edges[u].push_back(v);
        edges_rev[v].push_back(u);
    }

    for (const auto& node : nodes) {
        if (visited.count(node)) continue;
        dfs(node);
    }
    visited.clear();

    while (!seen.empty()) {
        const string u = seen.back();
        seen.pop_back();

        if (visited.count(u)) continue;
        dfs_rev(u);
        num_components += 1;
    }

    vector<vector<string>> ans;
    vector<string> avoid;

    for (auto kv : components) {
        if (kv.second.size() == 1) {
            avoid.push_back(kv.second[0]);
        } else if (kv.second.size() > 1) {
            sort(kv.second.begin(), kv.second.end());
            ans.push_back(kv.second);
        }
    }
    sort(ans.begin(), ans.end());
    sort(avoid.begin(), avoid.end());

    for (const auto& a : ans) {
        cout << "okay ";
        for (const auto& node : a) {
            cout << node << " ";
        }
        cout << endl;
    }
    if (avoid.size() > 0) {
        cout << "avoid ";
        for (const auto& a : avoid) {
            cout << a << " ";
        }
        cout << endl;
    }
}
