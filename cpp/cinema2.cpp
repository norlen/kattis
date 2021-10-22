#include <iostream>

using namespace std;

int main() {
    int n, m, g;
    cin >> n >> m;

    int s = 0, i;
    for (i = 0; i < m; ++i) {
        cin >> g;
        s += g;
        if (s > n) break;
    }
    cout << (m-i) << endl;
}
