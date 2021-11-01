#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    double p, sum = 0;
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        sum += t;
    }

    if (p == 100) {
        cout << "impossible\n";
    } else {
        int ans = ceilf64((p*n - sum) / (100 - p));
        cout << ans << endl;
    }
}