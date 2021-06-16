#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> in(n);
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }

    int moves = 1; // First not blank.
    for (int i = 0; i < m; ++i) {
        bool move = false;
        for (int j = 0; j < n; ++j) {
            if (in[j][i] == '$') {
                move = true;
                break;
            }
        }
        if (move == false) moves++; // No two blanks in a row, last non-blank.
    }

    cout << moves << endl;
}