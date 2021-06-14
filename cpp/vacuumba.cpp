#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed << setprecision(10);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;

        double angle = M_PI / 2, x = 0.0, y = 0.0;
        for (int i = 0; i < n; ++i) {
            double a, d;
            cin >> a >> d;
            angle += a / 180.0 * M_PI;
            x += cos(angle) * d;
            y += sin(angle) * d;
        }

        cout << x << " " << y << endl;
    }
}