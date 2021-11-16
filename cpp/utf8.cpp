#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> counts(5, 0);
    bool valid = true;
    int type = 0;
    int cb = 0;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (cb == 0) {
            if (s[0] == '0') {
                type = 1;
            } else if (s.substr(0,3) == "110") {
                type = 2;
            } else if (s.substr(0,4) == "1110") {
                type = 3;
            } else if (s.substr(0,5) == "11110") {
                type = 4;
            } else {
                valid = false;
                break;
            }
            cb++;
        } else {
            if (s.substr(0,2) == "10") {
                cb++;
            } else {
                valid = false;
                break;
            }
        }

        if (cb == type) {
            counts[type]++;
            cb = 0;
            type = 0;
        }
    }
    valid = valid && type == 0;

    if (!valid) {
        cout << "invalid\n";
    } else {
        for (int i = 1; i < counts.size(); ++i) {
            cout << counts[i] << endl;
        }
    }
}
