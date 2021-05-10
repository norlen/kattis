#include <iostream>
#include <array>
#include <stack>

using namespace std;

array<array<pair<int,int>, 1000>, 1000> grid;
array<array<bool, 1000>, 1000> visited;

int main() {
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; ++i) {
        string in;
        cin >> in;
        for (int j = 0; j < c; ++j) {
            grid[i][j] = { in[j] - '0', -1 };
        }
    }

    int component = 0;
    pair<int,int> offsets[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (visited[i][j]) continue;

            stack<pair<int,int>> s;
            s.push({i, j});
            visited[i][j] = true;

            int val = grid[i][j].first;
            while (s.size() > 0) {
                auto u = s.top();
                s.pop();
                grid[u.first][u.second].second = component;

                for (auto o : offsets) {
                    int vr = u.first + o.first;
                    int vc = u.second + o.second;
                    if (vr < 0 || vr >= r || vc < 0 || vc >= c || grid[vr][vc].first != val || visited[vr][vc]) continue;
                    s.push({vr, vc});
                    visited[vr][vc] = true;
                }
            }
            component++;
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int r0, c0, r1, c1;
        cin >> r0 >> c0 >> r1 >> c1;

        auto p0 = grid[r0-1][c0-1];
        auto p1 = grid[r1-1][c1-1];
        if (p0.first == p1.first && p0.second == p1.second) {
            cout << (p1.first == 0 ? "binary\n" : "decimal\n");
        } else {
            cout << "neither\n";
        }
    }
}