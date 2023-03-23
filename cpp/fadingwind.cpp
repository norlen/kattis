#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int h, k, v, s;
    cin >> h >> k >> v >> s;

    int horizontal_move = 0;
    while (h > 0) {
        v += s;
        v -= max(1, (int)floor(v / 10));
        if (v >= k) {
            h += 1;
        } else if (v > 0) {
            h -= 1;
            if (h == 0) v = 0;
        } else {
            h = 0;
            v = 0;
        }
        horizontal_move += v;

        if (s > 0) {
            s -= 1;
        }
    }
    
    cout << horizontal_move << endl;
}
