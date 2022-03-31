#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    string in;
    getline(cin, in);

    int control = 7;
    for (int i = 0; i < n; ++i) {
        getline(cin, in);
        if (in[5] == 'o') {
            control = min(10, control + 1);
        } else {
            control = max(0, control - 1);
        }
    }

    cout << control << endl;
}
