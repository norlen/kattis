#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    while (true) {
    double x1, y1, x2, y2, p;
        cin >> x1;
        if (x1 == 0) break;
        cin >> y1 >> x2 >> y2 >> p;

        double a = abs(x1 - x2);
        double b = abs(y1 - y2);
        cout << fixed << setprecision(10) << pow(pow(a, p) + pow(b, p), 1.0/p) << endl;
    }
}