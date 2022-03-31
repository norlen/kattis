#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ok(const string& s) {
    if (s.size() < 2 || s.size() % 2 == 1) return false;

    int n = s.size();
    for (int i = 0; i < n/2-1; ++i) {
        if (s[i] != '|' || s[n-i-1] != '|') {
            return false;
        }
    }

    return s[n/2-1] == '(' && s[n/2] == ')';
}

int main() {
    string in;
    cin >> in;

    if (ok(in)) {
        cout << "correct\n";
    } else {
        cout << "fix\n";
    }
}
