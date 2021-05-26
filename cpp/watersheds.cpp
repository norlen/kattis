#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int t = 0; t < cases; ++t) {
        int r, c;
        cin >> r >> c;

        vector<vector<bool>> visited(r);
        vector<vector<int>> grid(r);
        vector<vector<char>> out(r);

        for (int i = 0; i < r; ++i) {
            grid[i] = vector<int>(c);
            visited[i] = vector<bool>(c);
            out[i] = vector<char>(c);
            for (int j = 0; j < c; ++j) {
                int v;
                cin >> v;
                grid[i][j] = v;
                visited[i][j] = false;
            }
        }

        pair<int,int> offsets[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        int l = 0;
        for (int i = 0; i < r*c; ++i) {
            pair<int,int> u = {i / c, i % c};
            if (visited[u.first][u.second]) continue;
            visited[u.first][u.second] = true;
            char cl = -1;

            stack<pair<int,int>> visits;
            while (true) {
                visits.push(u);

                // Find lowest node around this.
                pair<int,pair<int,int>> lowest;
                bool found_lowest = false;
                for (int j = 0; j < 4; ++j) {
                    pair<int,int> v = {u.first + offsets[j].first, u.second + offsets[j].second};

                    if (v.first < 0 || v.first >= r || v.second < 0 || v.second >= c) continue;
                    if (grid[u.first][u.second] <= grid[v.first][v.second]) continue;

                    if (found_lowest == false || lowest.first > grid[v.first][v.second]) {
                        lowest = {grid[v.first][v.second], v};
                        found_lowest = true;
                    }
                }

                if (found_lowest) {
                    auto v = lowest.second;
                    // If we have visited this, mark with same label.
                    if (visited[v.first][v.second]) {
                        cl = out[v.first][v.second];
                    } else {
                        visited[v.first][v.second] = true;
                        u = v;
                        continue; // Only continue if we found a lowest that we havent visited.
                    }
                }
                break;
            }

            if (cl == -1) cl = 'a' + l++;
            while (!visits.empty()) {
                auto cc = visits.top();
                visits.pop();
                out[cc.first][cc.second] = cl;
            }
        }

        // Output.
        cout << "Case #" << t+1 << ":\n";
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << out[i][j] << (j != c-1 ? " " : "");
            }
            cout << endl;
        }
    }


}