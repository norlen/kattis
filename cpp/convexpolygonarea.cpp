#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    cout << setprecision(10);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        vector<pair<double, double>> points(m);
        for (int j = 0; j < m; ++j) cin >> points[j].first >> points[j].second;

        // Shoelace formula: https://en.wikipedia.org/wiki/Shoelace_formula
        double a = 0.0, b = 0.0;
        for (int j = 0; j < m; ++j) {
            a += points[j].first * points[(j+1) % m].second;
            b += points[(j+1) % m].first * points[j].second;
        }
        cout << abs(1.0/2.0 * (a - b)) << endl;
    }
}