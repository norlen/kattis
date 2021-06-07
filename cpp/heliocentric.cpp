#include <iostream>

using namespace std;

int main() {
    int e, m;
    int t = 1;

    while (cin >> e >> m) {
        constexpr int me = 365;
        constexpr int mm = 687;

        // brute force.
        int ans = 0;
        while ((e++ % me) != (m++ % mm)) ans++;
        --e;

        cout << "Case " << t << ": " << (ans + e % me) << endl;
        t++;
    }
}