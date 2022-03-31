#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string convert(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = tolower(s[i]);
        }
        if (s[i] == '-') {
            s[i] = ' ';
        }
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    string in;
    getline(cin, in);

    set<string> ans;
    for (int i = 0; i < n; ++i) {
        getline(cin, in);
        ans.insert(convert(in));
    }
    cout << ans.size() << endl;
}
