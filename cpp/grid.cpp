#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            grid[i][j] = ch - '0';
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    using T = pair<int, pair<int,int>>;
    deque<T> q;
    q.push_back({0, {0,0}});
    visited[0][0] = true;

    int best_cost = -1;
    const pair<int,int> offsets[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while (!q.empty()) {
        int cost = q.front().first;
        pair<int,int> u = q.front().second;
        q.pop_front();

        if (u.first == n-1 && u.second == m-1) {
            best_cost = cost;
            break;
        }

        int v = grid[u.first][u.second];
        for (auto o : offsets) {
            int vr = u.first + o.first * v;
            int vc = u.second + o.second * v;

            if (vr < 0 || vr >= n || vc < 0 || vc >= m || visited[vr][vc]) continue;
            visited[vr][vc] = true;
            q.push_back({cost + 1, {vr, vc}});
        }
    }
    
    cout << best_cost << endl;
}
