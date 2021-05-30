#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        c[i] = m;
    }
    sort(c.rbegin(), c.rend());

    bool impossible = false;
    double f = 1.0;
    for (int i = 0; i < n; ++i) {
        int cap = n - i;
        if (c[i] > cap) {
            impossible = true;
            break;
        }
        f = min(f, (double)c[i] / (double)cap);
    }

    if (impossible) {
        cout << "impossible\n";
    } else {
        cout << setprecision(10) << f << endl;
    }
}
