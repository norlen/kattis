#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    int grid[8][8];
    pair<int,int> offsets[8] = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

    for (int i = 0; i < n; ++i) {
        // Reset.
        for (int a = 0; a < 8; ++a) {
            for (int b = 0; b < 8; ++b) {
                grid[a][b] = -1;
            }
        }

        string start_pos;
        cin >> start_pos;

        int r = 7 - (start_pos[1] - '1');
        int c = start_pos[0] - 'a';

        deque<pair<int,int>> q;
        q.push_back({r, c});
        grid[r][c] = 0;

        int mval = 0;
        while (!q.empty()) {
            pair<int,int> u = q.front();
            q.pop_front();

            for (auto o : offsets) {
                int vr = u.first + o.first;
                int vc = u.second + o.second;
                if (vr < 0 || vr >= 8 || vc < 0 || vc >= 8 || grid[vr][vc] != -1) continue;
                
                grid[vr][vc] = grid[u.first][u.second] + 1;
                mval = max(mval, grid[vr][vc]);

                q.push_back({vr, vc});
            }
        }

        cout << mval;

        for (int a = 0; a < 8; ++a) {
            for (int b = 0; b < 8; ++b) {
                if (grid[a][b] == mval) {
                    cout << ' ' << (char)('a' + b) << (char)('1' + (7 - a));
                }
            }
        }
        cout << endl;
    }
}