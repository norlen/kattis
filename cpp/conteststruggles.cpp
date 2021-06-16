#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double n, k, d, s;
    cin >> n >> k >> d >> s;

    double a = (d*n - s*k) / (n-k);
    if (a > 100.0 || a < 0.0) {
        cout << "impossible\n";
    } else {
        cout << fixed << setprecision(10) << a << endl;
    }
}