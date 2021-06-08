#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string cmd, a, b;
    unordered_map<string, int> m;

    while (cin >> cmd) {
        int i;
        char op;
        if (cmd == "define") {
            cin >> i >> a;
            if (m.count(a) == 0) {
                m.insert({a, i});
            } else {
                m[a] = i;
            }
        } else if (cmd == "eval") {
            cin >> a >> op >> b;
            if (m.count(a) == 0 || m.count(b) == 0) {
                cout << "undefined\n";
            } else {
                bool cond;
                switch (op) {
                    case '<': cond = m[a] < m[b]; break;
                    case '>': cond = m[a] > m[b]; break;
                    case '=': cond = m[a] == m[b]; break;
                }
                cout << (cond ? "true\n" : "false\n");
            }
        }
    }
}