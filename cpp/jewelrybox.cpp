#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    // Volume: a*b*h, where a and b are sides of the rectangle.
    // a = x - 2h, b = y - 2h
    // V = (x - 2h)(y - 2h)*h
    //   = (xy - 2xh - 2yh + 4h^2)h
    //   = xyh - 2xh^2 - 2yh^2 + 4h^3
    // dV/dh = xy - 4xh - 4yh + 12h^2
    //       = 12h^2 - h((x+y)/3) + xy/12 = 0
    //     h = (x+y)/6 + (((x+y)/6)^2 - xy/12)^(1/2)
    for (int i = 0; i < t; ++i) {
        double x, y;
        cin >> x >> y;
        double h = (x+y)/6.0 - powf64(powf64((x+y)/6.0, 2.0) - x*y/12.0, 0.5);
        double h2 = (x+y)/6.0 + powf64(powf64((x+y)/6.0, 2.0) - x*y/12.0, 0.5);
        cout << fixed << setprecision(10) << max((x-2*h)*(y-2*h)*h, (x-2*h2)*(y-2*h2)*h2) << endl;
    }
}