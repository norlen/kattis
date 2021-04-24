#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    int tprev;
    double vprev;
    cin >> tprev >> vprev;
    double a = 0.0;
    for (int i = 1; i < n; ++i) {
        int t;
        double v;
        cin >> t >> v;
        a += (vprev + v) / 2.0 * (t - tprev);
        tprev = t;
        vprev = v;
    }
    cout << fixed << setprecision(10) << a/1000.0 << endl;
}