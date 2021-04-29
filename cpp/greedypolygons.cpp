#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    cout << fixed << setprecision(10);

    for (int i = 0; i < t; ++i) {
        int n, l, d, g;
        cin >> n >> l >> d >> g;
        // n: num sides
        // l: intitial side length
        // d: expansion distance
        // g: num land grabs

        double dn = (double)n;
        double dl = (double)l;
        double dd = (double)d;
        double dg = (double)g;

        // Area of polygon: A = (L2 n)/[4 tan (180/n)]
        double area = dl*dl*dn / (4.0 * tanf64(M_PIf64 / dn));

        // Each side increased by n rects: (exp dist * land_grab) * side_length
        // The soft sides is a full circle so: pi*r^2.
        double inc = dn*dl*dd*dg;
        double cr = dd*dg;
        double cinc = cr*cr*M_PIf64;
        cout << area + inc + cinc << endl;
    }
}