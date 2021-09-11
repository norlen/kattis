#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;

        vector<ll> v1(n), v2(n);
        for (int i = 0; i < n; ++i) {
            cin >> v1[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> v2[i];
        }

        // Multiply lowest with highest numbers.
        sort(v1.begin(), v1.end());
        sort(v2.rbegin(), v2.rend());

        ll scalar_product = 0;
        for (int i = 0; i < n; ++i) {
            ll add = v1[i] * v2[i];
            scalar_product += add;
        }

        cout << "Case #" << t+1 << ": " << scalar_product << endl;
    }
}