#include <iostream>

using namespace std;

int main() {
    // mosquitoes, pupae, larvae.
    // e: number of eggs by one mosquito.
    // r and s: survival rates for larvae and pupae.
    // n: number of weeks.
    int m, p, l, e, r, s, n;
    while (cin >> m >> p >> l >> e >> r >> s >> n) {
        for (int i = 0; i < n; ++i) {
            // New values for this week.
            int eggs = m * e;
            m = p / s;
            p = l / r;
            l = eggs;
        }

        cout << m << endl;
    }
}