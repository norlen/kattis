#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    int current = 0;
    int lowest = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        current += a;

        lowest = min(lowest, current);
    }

    cout << 0 - min(lowest, 0) << endl;
}
