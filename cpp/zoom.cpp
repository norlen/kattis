#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, k, t;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> t;
        if ((i+1) % k == 0) {
            cout << t << " "; 
        }
    }
    cout << endl;
}
