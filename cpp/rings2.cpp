#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char ch;
            cin >> ch;
            grid[i][j] = ch == 'T' ? 1 : 0;
        }
    }

    const pair<int,int> offsets[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int curr = 1;
    while (true) {
        bool dirty = false;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                bool surrounded = true;
                for (auto o : offsets) {
                    int vr = i + o.first;
                    int vc = j + o.second;
                    if (vr < 0 || vr >= r || vc < 0 || vc >= c || grid[vr][vc] < curr) {
                        surrounded = false;
                        break;
                    }
                }

                if (surrounded) {
                    dirty = true;
                    grid[i][j]++;
                }
            }
        }

        if (dirty == false) break;
        curr++;
    }

    int w = curr > 10 ? 3 : 2;
    string empty(w, '.');

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] > 0) {
                cout << setw(w) << setfill('.') << grid[i][j];
            } else {
                cout << empty;
            }
        }
        cout << endl;
    }
}


    // vector<vector<int>> t(r, vector<int>(c, 0));

    // // Look at all dots to find starting locations.
    // stack<pair<int,int>> start;

    // // Actual BFS queue to add rings.
    // deque<pair<int,int>> q;

    // for (int i = 0; i < r; ++i) {
    //     for (int j = 0; j < c; ++j) {
    //         char ch;
    //         cin >> ch;
    //         if (ch == 'T') {
    //             t[i][j] = 1;
    //             // Also add to queue if this is part of the edge.
    //             if (i == 0 || j == 0) {
    //                 t[i][j] = 2;
    //                 q.push_back({i, j});
    //             }
    //         } else {
    //             start.push({i, j});
    //         }
    //     }
    // }

    // vector<vector<int>> values(r, vector<int>(c, 0));
    // constexpr pair<int,int> offsets[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // while (!start.empty()) {
    //     pair<int,int> u = start.top();
    //     start.pop();

    //     for (auto o : offsets) {
    //         int vr = u.first + o.first;
    //         int vc = u.second + o.second;
    //         if (vr < 0 || vr >= r || vc < 0 || vc >= c || t[vr][vc] != 1) continue;
    //         t[vr][vc] = 2;
    //         q.push_back({vr, vc});
    //     }
    // }

    // int curr = 1;
    // while (!q.empty()) {
    //     int size = q.size();
    //     for (int i = 0; i < size; ++i) {
    //         pair<int,int> u = q.front();
    //         q.pop_front();
    //         values[u.first][u.second] = curr;

    //         for (auto o : offsets) {
    //             int vr = u.first + o.first;
    //             int vc = u.second + o.second;
    //             if (vr < 0 || vr >= r || vc < 0 || vc >= c || t[vr][vc] != 1) continue;
    //             t[vr][vc] = 2;
    //             q.push_back({vr, vc});
    //         }
    //     }
    //     ++curr;
    // }
    // int w = 1;
    // string empty = ".";
    // while (curr > 0) {
    //     curr /= 10;
    //     w++;
    //     empty.push_back('.');
    // }

    // for (int i = 0; i < r; ++i) {
    //     for (int j = 0; j < c; ++j) {
    //         if (values[i][j] > 0) {
    //             cout << setw(w) << setfill('.') << values[i][j];
    //         } else {
    //             cout << empty;
    //         }
    //     }
    //     cout << endl;
    // }

}