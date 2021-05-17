#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n);
    vector<pair<int,int>> row_colors;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            grid[i].push_back((c == 'W' ? 1 : 0));
        }
    }

    bool is_ok = true;
    for (int i = 0; i < n && is_ok; ++i) {
        // For checking cols.
        pair<int,int> c = {0, 0};
        int curr = 0;

        // For checkings rows.
        pair<int,int> r = {0, 0};
        int rcurr = 0;
        for (int j = 0; j < n && is_ok; ++j) {
            // Check no more than 3.
            curr += grid[i][j];
            rcurr += grid[j][i];
            if (j >= 2) {
                is_ok = curr != 0 && curr != 3 && rcurr != 0 && rcurr != 3;
                curr -= grid[i][j-2];
                rcurr -= grid[j-2][i];
            }

            // Check total colors per row/col.
            if (grid[i][j] == 1) { c.first++; } else { c.second++; }
            if (grid[j][i] == 1) { r.first++; } else { r.second++; }
        }
        is_ok = is_ok && c.first == c.second && r.first == r.second;
    }
    cout << (is_ok == true ? 1 : 0) << endl;
}