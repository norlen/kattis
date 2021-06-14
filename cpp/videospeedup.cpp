#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed << setprecision(10);

    int n, p, k;
    cin >> n >> p >> k;
    double pp = static_cast<double>(p) / 100.0;

    double ans = 0, speedup = 1.0;
    int prev = 0, t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        double duration = t - prev;
        ans += duration * speedup;

        speedup += pp;
        prev = t;
    }
    ans += (k - prev) * speedup;
    cout << ans << endl;
}