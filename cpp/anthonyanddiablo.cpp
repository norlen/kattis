#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, n;
    cin >> a >> n;

    // Circle:
    // A = pi*r^2 => sqrt(A/pi) = r
    // D = pi*r*2
    // D = pi*2*sqrt(A/pi)
    double d = M_PI * 2.0 * sqrt(a / M_PI);
    if (d <= n) {
        cout << "Diablo is happy!\n";
    } else {
        cout << "Need more materials!\n";
    }
}