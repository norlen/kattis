#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double r, m, c;
    while (true) {
        cin >> r >> m >> c;
        if (r == 0 && m == 0 && c == 0) break;

        double area = M_PI*r*r;
        double est = c / m * 4*r*r;
        cout << fixed << setprecision(10) << area << " " << est << endl;
    }
}