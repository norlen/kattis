#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr char AIR = '.';
constexpr char STONE = '#';
constexpr char WATER = 'V';

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vector<string> next(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        next[i] = grid[i];
    }

    while (true) {
        bool change = false;
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == WATER) {
                    if (grid[i+1][j] == STONE) {
                        if (j > 0 && grid[i][j-1] == AIR) {
                            change = true;
                            next[i][j-1] = WATER;
                        }
                        if (j < m-1 && grid[i][j+1] == AIR) {
                            change = true;
                            next[i][j+1] = WATER;
                        }
                    }
                    if (grid[i+1][j] == AIR) {
                        next[i+1][j] = WATER;
                        change = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            grid[i] = next[i];
        }

        if (change == false) break;
    }

    for (int i = 0; i < n; ++i) {
        cout << grid[i] << endl;
    }
}
