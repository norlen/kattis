#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int state;
int getb(int bit) {
    int mask = (1 << bit);
    int b = (state & mask) >> bit;
    return b;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> oct >> state;

        int winner = -1;
        for (int turn = 0; turn <= 1; ++turn) {
            if (getb(0) && getb(9) == turn &&
                getb(1) && getb(10) == turn &&
                getb(2) && getb(11) == turn) {
                winner = turn;
                break;
            }
            if (getb(3) && getb(12) == turn &&
                getb(4) && getb(13) == turn &&
                getb(5) && getb(14) == turn) {
                winner = turn;
                break;
            }
            if (getb(6) && getb(15) == turn &&
                getb(7) && getb(16) == turn &&
                getb(8) && getb(17) == turn) {
                winner = turn;
                break;
            }

            if (getb(0) && getb(9) == turn &&
                getb(3) && getb(12) == turn &&
                getb(6) && getb(15) == turn) {
                winner = turn;
                break;
            }
            if (getb(1) && getb(10) == turn &&
                getb(4) && getb(13) == turn &&
                getb(7) && getb(16) == turn) {
                winner = turn;
                break;
            }
            if (getb(2) && getb(11) == turn &&
                getb(5) && getb(14) == turn &&
                getb(8) && getb(17) == turn) {
                winner = turn;
                break;
            }

            if (getb(0) && getb(9) == turn &&
                getb(4) && getb(13) == turn &&
                getb(8) && getb(17) == turn) {
                winner = turn;
                break;
            }
            if (getb(2) && getb(11) == turn &&
                getb(4) && getb(13) == turn &&
                getb(6) && getb(15) == turn) {
                winner = turn;
                break;
            }
        }

        bool is_draw = false;
        if (winner == -1) {
            bool draw = true;
            for (int i = 0; i < 9; ++i) {
                if (getb(i) == 0) {
                    draw = false;
                    break;
                }
            }
            is_draw = draw;
        }

        if (winner >= 0) {
            if (winner == 0) {
                cout << "O wins\n";
            } else {
                cout << "X wins\n";
            }
        } else {
            if (is_draw) {
                cout << "Cat's\n";
            } else {
                cout << "In progress\n";
            }
        }
    }
}
