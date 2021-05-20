#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    
    vector<string> grid;
    for (int i = 0; i < r; ++i) {
        string row;
        cin >> row;
        grid.push_back(row);
    }

    string smallest;
    bool valid = false;

    // check cols.
    for (auto row : grid) {
        bool done = false;
        while (row.length() > 0) {
            int e = row.find('#');
            string s;
            if (e == string::npos) {
                s = row;
                done = true;
            } else {
                s = row.substr(0, e);
            }
            if (s.length() >= 2) {
                if (s < smallest || valid == false) {
                    smallest = s;
                    valid = true;
                }
            }
            if (done) break;
            row = row.substr(e+1);
        }
    }

    // check rows.
    for (int i = 0; i < c; ++i) {
        string col;
        for (int j = 0; j < r; ++j) {
            col.push_back(grid[j][i]);
        }
        bool done = false;
        while (col.length() > 0) {
            int e = col.find('#');
            string s;
            if (e == string::npos) {
                s = col;
                done = true;
            } else {
                s = col.substr(0, e);
            }
            if (s.length() >= 2) {
                if (s < smallest || valid == false) {
                    smallest = s;
                    valid = true;
                }
            }
            if (done) break;
            col = col.substr(e+1);
        }
    }

    cout << smallest << endl;
}