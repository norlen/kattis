#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, numeric_limits<int>::max()));
    using T = pair<int,pair<int,int>>;
    priority_queue<T, vector<T>, greater<T>> pq;
    dist[0][0] = 0;
    pq.push({0, {0,0}});

    const pair<int,int> offsets[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while (!pq.empty()) {
        pair<int,int> u = pq.top().second;
        int c = pq.top().first;
        pq.pop();

        if (u.first == n-1 && u.second == m-1) {
            cout << c << endl;
            return 0;
        }

        for (auto o : offsets) {
            int vr = u.first + o.first;
            int vc = u.second + o.second;
            if (vr < 0 || vr >= n || vc < 0 || vc >= m) continue;

            int d = max(0, grid[vr][vc] - grid[u.first][u.second]);
            int ladder_h = max(c, d);
            if (ladder_h < dist[vr][vc]) {
                dist[vr][vc] = ladder_h;
                pq.push({ladder_h, {vr, vc}});
            }
        }
    }
}
