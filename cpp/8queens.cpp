#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(const vector<string>& grid, int x, int y) {
    int n = 8;
    int i, j;

    // Check col.
    for (int i = 0; i < n; ++i) {
        if (i == x) continue;
        if (grid[y][i] == '*') {
            return false;
        }
    }

    // check row.
    for (int i = 0; i < n; ++i) {
        if (i == y) continue;
        if (grid[i][x] == '*') {
            return false;
        }
    }

    // check top-left, bot-right diag
    i = y-1;
    j = x-1;
    while (i >= 0 && j >= 0) {
        if (grid[i][j] == '*') {
            return false;
        }
        --i;
        --j;
    }
    i = y+1;
    j = x+1;
    while (i < n && j < n) {
        if (grid[i][j] == '*') {
            return false;
        }
        ++i;
        ++j;
    }

    // check bot-left, top-right diag
    i = y+1;
    j = x-1;
    while (i < n && j >= 0) {
        if (grid[i][j] == '*') {
            return false;
        }
        ++i;
        --j;
    }
    i = y-1;
    j = x+1;
    while (i >= 0 && j < n) {
        if (grid[i][j] == '*') {
            return false;
        }
        --i;
        ++j;
    }
    return true;
}

int main() {
    vector<string> grid(8);
    for (int i = 0; i < 8; ++i) cin >> grid[i];

    bool invalid = false;
    int queen_count = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (grid[i][j] == '*') {
                queen_count++;
                if (check(grid, j, i) == false) {
                    invalid = true;
                    break;
                }
            }
        }
        if (invalid) break;
    }

    if (invalid || queen_count != 8) {
        cout << "invalid\n";
    } else {
        cout << "valid\n";
    }
}