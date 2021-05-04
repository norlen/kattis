#include <iostream>
#include <array>
#include <deque>

using namespace std;

struct P {
    int l;
    int r;
    int c;
    int d;
    P(int l, int r, int c, int d): l(l), r(r), c(c), d(d) {};
    P() {};
};

int main() {
    while (true) {
        int l, r, c;
        string in;
        cin >> l >> r >> c;
        getline(cin, in);
        if (l == 0 && r == 0 && c == 0) break;

        array<array<array<int, 30>, 30>, 30> grid;
        array<array<array<int, 30>, 30>, 30> visited;
        P s;

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < r; ++j) {
                getline(cin, in);
                for (int k = 0; k < c; ++k) {
                    visited[i][j][k] = false;
                    grid[i][j][k] = in[k];
                    if (in[k] == 'S') {
                        s = P(i, j, k, 0);
                    }
                }
            }
            getline(cin, in);
        }

        int dr[] = {1, -1, 0, 0, 0, 0};
        int dc[] = {0, 0, 1, -1, 0, 0};
        int dl[] = {0, 0, 0, 0, 1, -1};

        deque<P> q;
        q.push_back(s);
        visited[s.l][s.r][s.c] = true;
        int time_to_escape = -1;
        while (q.size() > 0) {
            auto u = q.front();
            q.pop_front();

            for (int i = 0; i < 6; ++i) {
                int vl = u.l + dl[i];
                int vr = u.r + dr[i];
                int vc = u.c + dc[i];

                if (vl < 0 || vr < 0 || vc < 0 || vl >= l || vr >= r || vc >= c) continue;
                if (grid[vl][vr][vc] == '#') continue;
                if (visited[vl][vr][vc]) continue;

                if (grid[vl][vr][vc] == 'E') {
                    // Found exit.
                    time_to_escape = u.d + 1;
                    q.clear();
                    break;
                }

                visited[vl][vr][vc] = true;
                q.push_back(P(vl, vr, vc, u.d + 1));
            }
        }

        if (time_to_escape != -1) {
            cout << "Escaped in " << time_to_escape << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }
    }

}