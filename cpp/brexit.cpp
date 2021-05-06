#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int c, p, x, l;
    cin >> c >> p >> x >> l;

    // first value holds initial partnerships, second holds current.
    vector<pair<int,int>> nodes(c+1);
    vector<vector<int>> edges(c+1);
    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        nodes[u].first++;
        nodes[u].second++;
        nodes[v].first++;
        nodes[v].second++;
    }

    deque<int> leaves;
    nodes[l].first = 0;
    leaves.push_back(l);

    bool done = false;
    while (leaves.size() > 0 && !done) {
        auto u = leaves.front();
        leaves.pop_front();
        if (u == x) {
            done = true;
            break;
        }
        // cout << "u=" << u << endl;

        for (auto v : edges[u]) {
            nodes[v].second--;
            // cout << "v=" << v << " f=" << nodes[v].first << " s=" << nodes[v].second << endl;
            if (nodes[v].first != 0 && nodes[v].second <= nodes[v].first/2) {
                nodes[v].first = 0;
                // cout << "adding " << v << endl;
                leaves.push_back(v);
            }
        }
    }

    if (done) {
        cout << "leave\n";
    } else {
        cout << "stay\n";
    }
}