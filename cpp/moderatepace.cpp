#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> distances(n, vector<int>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distances[j][i];
        }
    }

    for (int i = 0; i < n; ++i) {
        sort(distances[i].begin(), distances[i].end());
        cout << distances[i][1] << (i == n-1 ? "\n" : " ");
    }
}
