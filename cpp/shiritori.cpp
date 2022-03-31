#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    unordered_set<string> seen;
    char prev = -1;
    for (int i = 0; i < n; ++i) {
        string in;
        cin >> in;

        bool wrong = prev != -1 && in[0] != prev;
        bool already_seen = seen.count(in) > 0;
        if (wrong || already_seen) {
            cout << "Player " << (i % 2)+1 << " lost\n";
            return 0;
        }
        prev = in[in.size()-1];
        seen.insert(in);
    }
    cout << "Fair Game\n";
    return 0;
}
