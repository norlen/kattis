#include <iostream>
#include <deque>
#include <array>
#include <vector>

using namespace std;

char grid[1001][1001];
int ss[1001][1001];
bool added[1001][1001];

int main() {
    int c, r;
    cin >> c >> r;

    int sr, sc;

    string input;
    getline(cin, input);
    for (int i = 0; i < r; ++i) {
        getline(cin, input);
        for (int j = 0; j < c; ++j) {
            grid[i][j] = input[j];
            if (grid[i][j] == 'M') {
                sr = i;
                sc = j;
                ss[i][j] = 0;
            } else if (grid[i][j] == '#') {
                ss[i][j] = -1;
            } else {
                ss[i][j] = 100000;
            }
        }
    }

    deque<pair<int,int>> q;
    q.push_back({sr, sc});
    added[sr][sc] = true;

    pair<int,int> offsets[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (q.size() > 0) {
        auto u = q.front();
        q.pop_front();
        int uy = u.first;
        int ux = u.second;

        for (int i = 0; i < 4; ++i) {
            int oy = offsets[i].first;
            int ox = offsets[i].second;
            int z = 1;
            int vy, vx;
            while (true) {
                vy = uy + oy*z;
                vx = ux + ox*z;
                if (grid[vy][vx] == '#') break;

                int d = ss[uy][ux] + 1;
                if ((ss[vy][vx] > d) && grid[vy][vx] != 'M') {
                    ss[vy][vx] = d;
                }
                if (grid[vy][vx] == '_') z++;
                else break;
            }
            if (z > 1 && grid[vy][vx] == '#') z--;
            vy = uy + oy*z;
            vx = ux + ox*z;

            bool should_add = grid[vy][vx] != '#';
            if (grid[vy][vx] == '_') {
                int c = 0;
                if (grid[vy][vx+1] == '#') c |= 1;
                if (grid[vy][vx-1] == '#') c |= 1;
                if (grid[vy+1][vx] == '#') c |= 2;
                if (grid[vy-1][vx] == '#') c |= 2;
                if (c != 3) should_add = false;
            }

            if (!added[vy][vx] && should_add) {
                added[vy][vx] = true;
                q.push_back({vy, vx});
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (ss[i][j] == 100000) ss[i][j] = -1;
            cout << ss[i][j] << " ";
        }
        cout << endl;
    }
}
