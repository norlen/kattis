#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool bfs(unordered_map<char, vector<char>>& e, char s, char t) {
    unordered_map<char, bool> visited;
    deque<char> q;
    q.push_back(s);

    while (!q.empty()) {
        auto u = q.front();
        q.pop_front();

        if (u == t) return true;

        for (auto v : e[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            q.push_back(v);
        }
    }
    return false;
}

bool ok(unordered_map<char, vector<char>>& e, const string& a, const string& b) {
    if (a.size() != b.size()) return false;

    for (int i = 0; i < a.size(); ++i) {
        if (!bfs(e, a[i], b[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int m, n;
    cin >> m >> n;

    unordered_map<char, vector<char>> e;
    for (int i = 0; i < m; ++i) {
        char a, b;
        cin >> a >> b;
        e[a].push_back(b);
    }

    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;

        if (ok(e, a, b)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}
