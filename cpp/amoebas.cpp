#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid;
    for (int i = 0; i < r; ++i) {
        grid.emplace_back(vector<char>(c));
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }


    deque<pair<int,int>> q;
    pair<int,int> offsets[8] = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1, 1}, {-1, -1}};
    int ans = 0;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] != '#') continue;
            grid[i][j] = ' ';
            ans++;
            q.push_back({i, j});
            while (!q.empty()) {
                pair<int,int> u = q.front();
                q.pop_front();

                for (pair<int,int> o : offsets) {
                    pair<int,int> v = {u.first + o.first, u.second + o.second};
                    if (v.first < 0 || v.first >= r || v.second < 0 || v.second >= c || grid[v.first][v.second] != '#') continue;
                    grid[v.first][v.second] = ' ';
                    q.push_back(v);
                }
            }
        }
    }
    
    cout << ans << endl;
}