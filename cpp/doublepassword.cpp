#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string a, b;
    cin >> a >> b;

    int ans = 1;
    for (int i = 0; i < 4; ++i) {
        if (a[i] != b[i]) {
            ans *= 2;
        }
    }
    cout << ans << endl;
}
