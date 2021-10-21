#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double dst(pair<double,double> a, pair<double,double> b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    double maxd = 0;
    for (int i = 0; i < 2; ++i) {
        pair<double,double> p[2];
        for (int j = 0; j < 2; ++j) {
            cin >> p[j].first;
            cin >> p[j].second;
        }
        maxd = max(maxd, dst(p[0], p[1]));
    }
    cout << setprecision(10) << maxd << endl;
}