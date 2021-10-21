#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    
    // Create and initialize grid, true if occupied.
    vector<vector<bool>> g(r);
    for (int i = 0; i < r; ++i) {
        g[i] = vector<bool>(c);
        for (int j = 0; j < c; ++j) {
            g[i][j] = false;
        }
    }

    // Insert starting positions.
    deque<pair<int,int>> p;
    for (int i = 0; i < n; ++i) {
        int vr, vc;
        cin >> vr >> vc;
        p.push_back({ vr-1, vc-1 }); // These are 1-indexed.
        g[vr-1][vc-1] = true;
    }

    const pair<int,int> offsets[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    // BFS with each day, one iteration over all points.
    int days = 0;
    while (!p.empty()) {
        days++;

        int s = p.size();
        for (int i = 0; i < s; ++i) {
            auto u = p.front();
            p.pop_front();

            for (auto o : offsets) {
                int vr = u.first + o.first;
                int vc = u.second + o.second;
                if (vr < 0 || vr >= r || vc < 0 || vc >= c || g[vr][vc]) continue;
                g[vr][vc] = true;
                p.push_back({vr, vc});
            }
        }
    }

    cout << days << endl;
}