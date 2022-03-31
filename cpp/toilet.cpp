#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string in;
    cin >> in;

    bool fup = in[0] == 'U';
    bool prev_up[3] = { fup, fup, fup };
    int policy[3] = {0,0,0};

    for (int i = 1; i < in.size(); ++i) {
        bool up = in[i] == 'U';

        // All are the same for entering, pick the position you want.
        for (int j = 0; j < 3; ++j) {
            if (prev_up[j] != up) {
                policy[j] += 1;
            }
        }

        // POLICY 0
        // When you leave, always leave the seat up
        // LEAVE: If up: nothing, else put up
        if (!up) {
            policy[0] += 1;
        }
        prev_up[0] = true;

        // POLICY 1
        // When you leave, always leave the seat down
        // LEAVE, put down
        if (up) {
            policy[1] += 1;
        }
        prev_up[1] = false;

        // POLICY 2
        // When you leave, always leave the seat as you would like to find it
        prev_up[2] = up;
    }

    for (int i = 0; i < 3; ++i) {
        cout << policy[i] << endl;
    }
}
