#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;

    unordered_map<string, int> nodes;
    unordered_map<string, vector<string>> edges;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string in;
        cin >> in;
        nodes.insert({in, 0});
    }

    unordered_set<string> visited;

    cin >> m;
    for (int i = 0; i < m; ++i) {
        string u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }


    bool impossible = false;
    int colors[2] = {1, 2};
    for (const auto& node : nodes) {
        if (visited.count(node.first)) continue;
        // give it random color.
        nodes[node.first] = 1;

        stack<string> s;
        s.push({node.first});

        while (!s.empty()) {
            string u = s.top();
            s.pop();
            int color = nodes[u];
            int other_color = color == 1 ? 2 : 1;

            for (const auto& v : edges[u]) {
                if (nodes[v] == color) {
                    impossible = true;
                    break;
                }
                if (visited.count(v)) continue;
                visited.insert(v);
                nodes[v] = other_color;
                s.push(v);
            }

            if (impossible) break;
        }

        if (impossible) break;
    }

    vector<string> wj[2];
    int turn = 0;
    for (auto kv : nodes) {
        // cout << kv.first << " color=" << kv.second << endl;
        if (kv.second == 0) {
            wj[turn].push_back(kv.first);
            turn = (turn + 1) % 2;
        } else {
            wj[kv.second-1].push_back(kv.first);
        }
    }

    if (impossible) {
        cout << "impossible\n";
    } else {
        for (int i = 0; i < 2; ++i) {
            for (const auto& s : wj[i]) {
                cout << s << " ";
            }
            cout << endl;
        }
    }
}
