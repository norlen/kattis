#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool starts_with(const string& s, const string& pat) {
    if (s.size() < pat.size()) return false;

    for (int i = 0; i < pat.size(); ++i) {
        if (s[i] != pat[i]) return false;
    }
    return true;
}

int main() {
    int n;
    string in;

    cin >> n;
    getline(cin, in);
    string pat = "simon says ";

    for (int i = 0; i < n; ++i) {
        getline(cin, in);
        if (starts_with(in, pat)) {
            cout << in.substr(pat.size()) << endl;
        } else {
            cout << endl;
        }
    }
}