#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
const pair<int,int> offsets[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void dbg(const vector<string>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
        cout << grid[i] << endl;
    }
}

int count_eb(const vector<string>& grid, int i, int j) {
    int count = 0;
    for (auto o : offsets) {
        int vr = i + o.first;
        int vc = j + o.second;
        if (vr < 0 || vr >= n || vc < 0 || vc >= m) continue;
        if (grid[vr][vc] == 'E') {
            count += 1;
        }
    }
    return count;
}

bool has_eb(const vector<string>& grid, int i, int j) {
    for (auto o : offsets) {
        int vr = i + o.first;
        int vc = j + o.second;
        if (vr < 0 || vr >= n || vc < 0 || vc >= m) continue;
        if (grid[vr][vc] == 'E') {
            return true;
        }
    }
    return false;
}

bool needs_eb(const vector<string>& grid, int i, int j) {
    return grid[i][j] != '#' && !has_eb(grid, i, j);
}

bool can_place(const vector<string>& grid, int i, int j) {
    if (i >= n || j >= m) return false;
    if (grid[i][j] == '#') return false;
    return !has_eb(grid, i, j);
}

int main() {
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];
    // dbg(grid);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!needs_eb(grid, i, j)) continue;

            if (can_place(grid, i, j+1)) {
                grid[i][j+1] = 'E';
                j += 2;
            } else if (can_place(grid, i+1, j)) {
                grid[i+1][j] = 'E';
                j += 1;
            } else {
                grid[i][j] = 'E';
                j += 1;
            }
        }
    }
    dbg(grid);

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         if (grid[i][j] == 'E' && count_eb(grid,i,j) > 1) {
    //             cout << "Invalid placement at i=" << i << ", j=" << j << endl;
    //         }
    //     }
    // }

}