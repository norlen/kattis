#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double x, y;
    int n;
    cin >> x >> y >> n;

    double ty = y;
    for (int i = 0; i < n; ++i) {
        double l, u, f;
        cin >> l >> u >> f;
        double d = u - l;
        y -= d - d*f;
    }
    cout << fixed << setprecision(10) << x/y << endl;
}