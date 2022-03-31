#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<int> bits(32, -1);
        for (int i = 0; i < n; ++i) {
            string cmd;
            int a, b;
            cin >> cmd;

            if (cmd == "SET") {
                cin >> a;
                bits[a] = 1;
            } else if (cmd == "CLEAR") {
                cin >> a;
                bits[a] = 0;
            } else if (cmd == "OR") {
                cin >> a >> b;
                if (bits[a] == -1 || bits[b] == -1) {
                    if (bits[a] == 1 || bits[b] == 1) {
                        bits[a] = 1;
                    } else {
                        bits[a] = -1;
                    }
                } else {
                    bits[a] = bits[a] | bits[b];
                }
            } else if (cmd == "AND") {
                cin >> a >> b;
                if (bits[a] == -1 || bits[b] == -1) {
                    if (bits[a] == 0 || bits[b] == 0) {
                        bits[a] = 0;
                    } else {
                        bits[a] = -1;
                    }
                } else {
                    bits[a] = bits[a] & bits[b];
                }
            }
        }

        for (int i = bits.size()-1; i >= 0; --i) {
            if (bits[i] == -1) {
                cout << '?';
            } else {
                cout << bits[i];
            }
        }
        cout << endl;
    }
}