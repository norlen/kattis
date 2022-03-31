#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Board {
public:
    Board(int n):
        n(n),
        board(n, vector<int>(n, 0)),
        cols(n, false),
        rows(n, false),
        diags(2*n-1, false),
        antidiags(2*n-1, false)
    {}

    void place_hole(int x, int y) {
        board[y][x] = -1;
    }

    void set(int x, int y, bool set) {
        cols[y] = set;
        rows[x] = set;
        diags[x + y] = set;
        antidiags[n + x -y - 1] = set;
    }

    bool can_place(int x, int y) {
        return !(
            board[y][x] == -1 || cols[y] || rows[x] || diags[x+y] || antidiags[n+x-y-1]
        );
    }

    int n;
    vector<vector<int>> board;
    vector<bool> cols;
    vector<bool> rows;
    vector<bool> diags;
    vector<bool> antidiags;
};

int solve(Board& b, int to_place) {
    if (to_place == 0) {
        return 1;
    }

    int x = b.n - to_place;
    int solutions = 0;
    for (int y = 0; y < b.n; ++y) {
        if (b.can_place(x, y)) {
            b.set(x, y, true);
            solutions += solve(b, to_place - 1);
            b.set(x, y, false);
        }
    }
    return solutions;
}

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0) break;

        Board b(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> y >> x;
            b.place_hole(x, y);
        }

        int solutions = solve(b, n);
        cout << solutions << endl;
    }
}
