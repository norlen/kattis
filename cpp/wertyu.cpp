#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string in;

    unordered_map<char, char> m;
    vector<string> samp = {
        "`1234567890-=",
        "QWERTYUIOP[]\\",
        "ASDFGHJKL;'",
        "ZXCVBNM,./",
    };

    for (int i = 0; i < samp.size(); ++i) {
        for (int j = 1; j < samp[i].size(); ++j) {
            m[samp[i][j]] = samp[i][j-1];
        }
    }

    while (getline(cin, in)) {
        for (auto ch : in) {
            if (m.count(ch) > 0) {
                cout << m[ch];
            } else {
                cout << ch;
            }
        }
        cout << endl;
    }
}
