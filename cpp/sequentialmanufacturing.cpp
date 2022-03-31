#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, p;
    cin >> n >> p;

    int b_v = 0;
    int b_i = 0;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        if (t[i] >= b_v) {
            b_v = t[i];
            b_i = i;
        }
    };

    ll before_b = 0;
    ll after_b = 0;
    for (int i = 0; i < n; ++i) {
        if (i < b_i) {
            before_b += t[i];
        } else {
            after_b += t[i];
        }
    }

    cout << before_b + p*after_b << endl;
}
