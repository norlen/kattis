#include <iostream>

using namespace std;

int main() {
    int n, m, g;
    cin >> n >> m;

    int s = 0, admitted = 0;
    for (int i = 0; i < m; ++i) {
        cin >> g;
        if (s + g > n) continue;
        s += g;
        admitted++;
    }
    cout << (m-admitted) << endl;
}
