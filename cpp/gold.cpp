#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool visited(const vector<vector<char>>& d, int i, int j) {
    return (d[i][j] & 0x1) > 0;
}

bool sense_trap(const vector<vector<char>>& d, int i, int j) {
    return (d[i][j] & 0x2) > 0;
}

int main() {
    int w, h;
    cin >> w >> h;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i]; // No spaces in the grid so this is fine.
    }

    const pair<int,int> offsets[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    pair<int,int> start_pos;

    vector<vector<char>> data(h); // First bit: visited, second bit: trap sens.
    for (int i = 0; i < h; ++i) {
        data[i] = vector<char>(w);
        for (int j = 0; j < w; ++j) {
            data[i][j] = 0;
        }
    }

    // Add the trap sensing to highest bit, as that's not used for these ascii characters.
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 'T') {
                for (auto o : offsets) {
                    int ny = i + o.first;
                    int nx = j + o.second;
                    data[ny][nx] |= 0x2; // Enclosed by walls, so this is fine.
                }
            } else if (grid[i][j] == 'P') {
                start_pos = {i, j};
            }
        }
    }

    // BFS and see which gold we can get.
    deque<pair<int,int>> q;
    q.push_back(start_pos);
    data[start_pos.first][start_pos.second] |= 0x1; // visit.
    int gold = 0;

    while (!q.empty()) {
        auto u = q.front();
        q.pop_front();
        if (grid[u.first][u.second] == 'G') {
            gold++;
        }
        if (sense_trap(data, u.first, u.second)) continue;

        for (auto o : offsets) {
            int ny = u.first + o.first;
            int nx = u.second + o.second;
            char v = grid[ny][nx];
            
            // Enclosed by walls, so no need to check bounds.
            if (visited(data, ny, nx) || v == '#' || v == 'T') continue;
            q.push_back({ny, nx});
            data[ny][nx] |= 0x1; // visit
        }
    }

    cout << gold << endl;
}