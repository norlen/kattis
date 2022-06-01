#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string to_str(int n) {
    string s;
    for (int i = 0; i < 4; ++i) {
        int mask = 1 << (3 - i);
        if (n & mask) {
            s.push_back('*');
        } else {
            s.push_back('.');
        }
    }
    return s;
}

int main() {
    string s;
    cin >> s;

    vector<string> ss(4);
    for (int i = 0; i < 4; ++i) {
        ss[i] = to_str(s[i] - '0');
    }

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            cout << ss[col][row] << (col != 3 ? " " : "");
            if (col == 1) {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
