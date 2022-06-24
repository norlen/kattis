#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double w = abs(x1 - x2);
    double h = abs(y1 - y2);
    cout << fixed << setprecision(8) << w*h << endl;
}
