#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, b;
    cin >> n;

    unordered_map<int, int> lookup;
    for (int i = 0; i <= 255; ++i) {
        int x = (i ^ (i << 1)) & 0xFF;
        lookup[x] = i;
    }


    for (int i = 0; i < n; ++i) {
        cin >> b;
        cout << lookup[b] << (i == n-1 ? "\n" : " ");
    }
}
