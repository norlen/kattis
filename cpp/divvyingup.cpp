#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, v;
    cin >> n;

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        sum += v;
    }

    cout << (sum % 3 == 0 ? "yes\n" : "no\n");
}
