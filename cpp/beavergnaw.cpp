#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        double D, V;
        cin >> D >> V;
        if (D == 0 && V == 0) break;

        double D3 = D*D*D;
        double d3 = D*D*D - 6.0*V/M_PI;
        cout << fixed << setprecision(10) << powf64(d3, 1.0/3.0) << endl;
    }
}