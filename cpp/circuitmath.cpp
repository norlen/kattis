#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    string in;
    char ch;

    vector<int> values(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        if (ch == 'T') {
            values[i] = 1;
        } else {
            values[i] = 0;
        }
    }

    getline(cin, in);
    getline(cin, in);

    stack<int> s;
    for (int i = 0; i < in.size(); ++i) {
        if (in[i] == ' ') continue;
        if (in[i] >= 'A' && in[i] <= 'Z') {
            s.push(values[in[i] - 'A']);
        }
        if (in[i] == '*') {
            int lhs = s.top();
            s.pop();
            int rhs = s.top();
            s.pop();
            // cout << lhs << " " << rhs << " * = " << (lhs & rhs) << endl;
            s.push(lhs & rhs);
        }
        if (in[i] == '+') {
            int lhs = s.top();
            s.pop();
            int rhs = s.top();
            s.pop();
            // cout << lhs << " " << rhs << " + = " << (lhs | rhs) << endl;
            s.push(lhs | rhs);
        }
        if (in[i] == '-') {
            int v = s.top();
            s.pop();
            // cout << v << " - = " << (v == 1 ? 0 : 1) << endl;
            s.push(v == 1 ? 0 : 1);
        }
    }

    if (s.top() == 1) {
        cout << 'T' << endl;
    } else {
        cout << 'F' << endl;
    }
}
