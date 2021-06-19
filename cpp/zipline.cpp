#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int p;
    cin >> p;

    for (int t = 0; t < p; ++t) {
        double w, g, h, r;
        cin >> w >> g >> h >> r;

        // Minimum length of cable.
        double minw = sqrt(pow(g - h, 2.0) + pow(w, 2.0));

        // Maximum length of cable using ternary search, with the ground split into (a, w-a).
        double y1 = g - r;
        double y2 = h - r;
        auto f = [y1, y2, w](double a) -> double {
            return sqrt(pow(y1, 2.0) + pow(a, 2.0)) + sqrt(pow(y2, 2.0) + pow(w - a, 2.0));
        };

        constexpr double EPS = 0.0000001;
        double a = 0, b = w;
        while (b-a > EPS) {
            double d = b - a;
            double m1 = a + d / 3.0;
            double m2 = b - d / 3.0;

            if (f(m1) < f(m2)) {
                b = m2;
            } else {
                a = m1;
            }
        }
        double maxw = f(a);

        cout << fixed << setprecision(10) << minw << " " << maxw << endl;
    }
}