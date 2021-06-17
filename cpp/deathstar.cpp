#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> m(n);
    for (int i = 0; i < n; ++i) {
        m[i] = vector<int>(n);
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i] |= m[i][j];
            a[j] |= m[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n-1 ? "" : " ");
    }
    cout << endl;
}