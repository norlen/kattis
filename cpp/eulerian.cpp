#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, u, v;
    cin >> n >> m;

    vector<vector<int>> fe(n);
    vector<vector<int>> be(n);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        fe[u-1].push_back(v-1);
        be[v-1].push_back(u-1);
    }

    int more_in = -1;
    int more_out = -1;
    for (int i = 0; i < n; ++i) {
        int in_deg = be[i].size();
        int out_deg = fe[i].size();
        if (in_deg == out_deg) {
            continue; // ok.
        } else if (in_deg + 1 == out_deg && more_out == -1) {
            more_out = i;
        } else if (out_deg + 1 == in_deg && more_in == -1) {
            more_in = i;
        } else {
            cout << "no\n";
            return 0;
        }
    }

    // Check if connected.
    stack<int> s;
    vector<bool> vis(n, false);
    int visited = 0;
    s.push(0);
    vis[0] = true;
    while (!s.empty()) {
        auto u = s.top();
        s.pop();
        visited++;

        for (auto v : fe[u]) {
            if (vis[v] == false) {
                vis[v] = true;
                s.push(v);
            }
        }
        for (auto v : be[u]) {
            if (vis[v] == false) {
                vis[v] = true;
                s.push(v);
            }
        }
    }
    if (visited != n) {
        cout << "no\n";
        return 0;
    }

    if (more_in == -1 && more_out == -1) {
        cout << "anywhere\n";
    } else if (more_in != -1 && more_out != -1) {
        cout << more_out+1 << " " << more_in+1 << endl;
    } else {
        cout << "no\n";
    }
}