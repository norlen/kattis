#include <iostream>
#include <vector>
#include <deque>

using namespace std;

constexpr char BLACK = '#';
constexpr char WHITE = '.';
constexpr pair<int,int> OFFSETS[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    int r, c, t = 1;
    while (cin >> r >> c) {
        vector<string> g(r);
        deque<pair<int,int>> q;

        for (int i = 0; i < r; ++i) {
            cin >> g[i];
        }

        int stars = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (g[i][j] == BLACK) continue;
                g[i][j] = BLACK;
                stars++;

                q.push_back({i, j});
                while (!q.empty()) {
                    pair<int,int> u = q.front();
                    q.pop_front();

                    for (pair<int,int> o : OFFSETS) {
                        int vr = u.first + o.first;
                        int vc = u.second + o.second;
                        if (vr < 0 || vr >= r || vc < 0 || vc >= c || g[vr][vc] == BLACK) continue;
                        g[vr][vc] = BLACK;
                        q.push_back({vr, vc});
                    }
                }
            }
        }

        cout << "Case " << t++ << ": " << stars << endl;
    }
}