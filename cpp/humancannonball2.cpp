#include <iostream>
#include <cmath>

using namespace std;

double G = 9.81;

double deg2rad(double deg) {
    return deg * M_PI / 180.0;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double v0, theta, x1, h1, h2;
        cin >> v0 >> theta >> x1 >> h1 >> h2;
        theta = deg2rad(theta);

        double t = x1 / (v0 * cosf64(theta));
        double y = v0 * t * sinf64(theta) - 1.0/2.0 * G * t * t;

        if ((h1 + 1.0) < y && y < (h2 - 1.0)) {
            cout << "Safe" << endl;
        } else {
            cout << "Not Safe" << endl;
        }
    }

}