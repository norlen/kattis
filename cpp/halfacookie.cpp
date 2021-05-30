#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double r, x, y;
    while (cin >> r >> x >> y) {
        double d = x*x + y*y;
        if (d > r*r) {
            cout << "miss\n";
        } else {
            // Area of a circular segment.
            // A = R^2*arccos(1 - h/R) - (R - h)*sqrt(R^2 - (R - h)^2)
            // https://en.wikipedia.org/wiki/Circular_segment

            double h = r - sqrt(d);

            double a = M_PI*r*r;
            double b = r*r * acos(1.0 - h/r) - (r - h)*sqrt(r*r - (r-h)*(r-h));
            cout << setprecision(10) << a - b << " " << b << endl;
        }
    }
}