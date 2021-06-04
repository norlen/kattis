#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<string> grid(r);
    for (int i = 0; i < r; ++i) {
        cin >> grid[i];
    }

    int islands = 0;
    deque<pair<int,int>> q;
    pair<int,int> offsets[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] != 'L') continue;
            islands++;
            grid[i][j] = 'W';
            q.push_back({i, j});
            while (!q.empty()) {
                pair<int,int> u = q.front();
                q.pop_front();

                for (pair<int,int> o : offsets) {
                    pair<int,int> v = {u.first + o.first, u.second + o.second};
                    if (v.first < 0 || v.first >= r || v.second < 0 || v.second >= c || grid[v.first][v.second] == 'W') continue;
                    grid[v.first][v.second] = 'W';
                    q.push_back(v);
                }
            }
        }
    }

    cout << islands << endl;
}