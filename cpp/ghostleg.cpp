#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m, a;
    cin >> n >> m;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        values[i] = i + 1;
    }

    for (int i = 0; i < m; ++i) {
        cin >> a;
        swap(values[a-1], values[a]);
    }
    
    for (int i = 0; i < n; ++i) {
        cout << values[i] << endl;
    }
}
