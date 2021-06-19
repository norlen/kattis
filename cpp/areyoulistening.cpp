#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int cx, cy, n;
    cin >> cx >> cy >> n;

    int d[4] = { INT32_MAX, INT32_MAX, INT32_MAX, 0 };
    for (int i = 0; i < n; ++i) {
        double x, y, r;
        cin >> x >> y >> r;
        d[3] = floor(sqrt(pow(cx - x, 2.0) + pow(cy - y, 2.0)) - r);
        d[3] = d[3] < 0 ? 0 : d[3];
        for (int j = 2; j >= 0; --j) {
            if (d[j] > d[j+1]) {
                swap(d[j+1], d[j]);
            }
        }
    }

    cout << d[2] << endl;
}