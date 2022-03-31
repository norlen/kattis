#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string in;
    getline(cin, in);

    list<char> l = {'S', 'E'};
    auto it = l.begin();
    ++it;

    for (auto ch : in) {
        if (ch == 'L') {
            if (*it != 'S') {
                --it;
            }
        } else if (ch == 'R') {
            if (*it != 'E') {
                ++it;
            }
        } else if (ch == 'B') {
            auto remove = it;
            --remove;
            if (*remove != 'S') {
                l.erase(remove);
            }
        } else {
            l.insert(it, ch);
        }
    }

    for (auto ch : l) {
        if (ch == 'S' || ch == 'E') continue;
        cout << ch;
    }
    cout << endl;
}