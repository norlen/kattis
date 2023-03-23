#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    stack<char> ss;

    bool valid = true;
    for (int i = 0; i < min(n, (int)s.size()) && valid; ++i) {
        char ch = s[i];
        switch (s[i]) {
            case '{': ss.push('}'); break;
            case '[': ss.push(']'); break;
            case '(': ss.push(')'); break;
            default:
                if (ss.size() == 0 || ss.top() != s[i]) {
                    valid = false;
                } else {
                    ss.pop();
                }
                break;
        }
    }
    cout << ((valid && ss.empty()) ? "Valid" : "Invalid") << endl;
}
