#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    // Cone volume: V = πr^2h/3 = Ah/3

    while (true) {
        int ind, inv;
        cin >> ind >> inv;
        if (ind == 0 && inv == 0) break;

        double D = ind;
        double V = inv;
        cout << "D=" << D << ", V=" << V << endl;
        double D3 = D*D*D;
        double other = 12.0*V/M_PI;
        cout << "D^3=" << D3 << " 12V/PI=" << other << endl;
        
        double d3 = D*D*D - 12.0*V/M_PI;
        cout << "d^3=" << d3 << endl;
        cout << powf64(d3, 1.0/3.0) << endl;
    }
}