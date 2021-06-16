#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int d;
    cin >> d;

    vector<string> g(d);
    for (int i = 0; i < d; ++i) cin >> g[i];

    // Find starting position.
    pair<int,int> s;
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < d; ++j) {
            if (g[i][j] == 'K') {
                s = {i, j};
                break;
            }
        }
    }

    // BFS from start until (1,1) is hit.
    const pair<int,int> offsets[8] = {{2,1}, {-2,1}, {2,-1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}};
    int min_moves = -1;
    deque<pair<int, pair<int,int>>> q;
    q.push_back({0, s});
    while (!q.empty()) {
        int moves = q.front().first;
        pair<int,int> u = q.front().second;
        q.pop_front();

        // If solution is found.
        if (u.first == 0 && u.second == 0) {
            min_moves = moves;
            break;
        }

        for (pair<int,int> o : offsets) {
            int r = u.first + o.first;
            int c = u.second + o.second;
            if (r < 0 || r >= d || c < 0 || c >= d || g[r][c] != '.') continue;
            g[r][c] = 'M';
            q.push_back({moves + 1, {r, c}});
        }
    }
    cout << min_moves << endl;
}