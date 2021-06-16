#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c, t = 1;
    while (true) {
        cin >> c >> r;
        if (r == 0 && c == 0) break;

        vector<string> g(r);
        for (int i = 0; i < r; ++i) {
            cin >> g[i];
        }

        // Find starting position.
        pair<int,int> pos = {-1, -1};
        pair<int,int> move = {-1, -1};
        for (int i = 0; i < r && pos.first == -1; ++i) {
            if (g[i][0] == '*') {
                pos = {i, 0};
                move = {0, 1};
            } else if (g[i][c-1] == '*') {
                pos = {i, c-1};
                move = {0, -1};
            }
        }
        for (int i = 0; i < c && pos.first == -1; ++i) {
            if (g[0][i] == '*') {
                pos = {0, i};
                move = {1, 0};
            } else if (g[r-1][i] == '*') {
                pos = {r-1, i};
                move = {-1, 0};
            }
        }

        // Find exit & replace.
        while (true) {
            pos.first += move.first;
            pos.second += move.second;
            char ch = g[pos.first][pos.second];
            if (ch == 'x') {
                break;
            } else if (ch == '/') {
                swap(move.first, move.second);
                move.first = -move.first;
                move.second = -move.second;
            } else if (ch == '\\') {
                swap(move.first, move.second);
            }
        }
        g[pos.first][pos.second] = '&';

        cout << "HOUSE " << t++ << endl;
        for (auto& s : g) {
            cout << s << endl;
        }
    }
}