#include <iostream>

using namespace std;

int main() {
    int sx, sy, tx, ty, t;
    cin >> sx >> sy >> tx >> ty >> t;

    int d = abs(sx - tx) + abs(sy - ty);
    bool ok = t >= d && (t-d) % 2 == 0;
    cout << (ok ? "Y\n" : "N\n");
}