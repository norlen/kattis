#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    // (x1, y1) bottom-left
    // (x2, y2) top-right.

    int fx, fy;
    if (x < x1) fx = x1;
    else if (x > x2) fx = x2;
    else fx = x;

    if (y < y1) fy = y1;
    else if (y > y2) fy = y2;
    else fy = y;

    double dx = abs(fx - x);
    double dy = abs(fy - y);
    double d = sqrt(dx*dx + dy*dy);
    cout << fixed << setprecision(10) << d << endl;
}