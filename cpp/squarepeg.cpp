#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    double l, r;
    cin >> l >> r;

    if (l <= 2*r/sqrt(2)) {
        cout << "fits\n";
    } else {
        cout << "nope\n";
    }
}
