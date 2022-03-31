#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n, t;
    cin >> n >> t;

    int a, b, c, t0;
    cin >> a >> b >> c >> t0;

    vector<int> penalty;
    if (t0 <= t) {
        penalty.push_back(t0);
    }

    int since_start = 0;
    for (int i = 0; i < n-1; ++i) {
        int solve = (((a * t0 + b) % c) + 1);
        if (since_start + solve > t) {
            break;
        }
        penalty.push_back(solve);
        t0 = solve;
        since_start += solve;
    }

    sort(penalty.begin(), penalty.end());
    ll p = 0;
    ll m = 1000000007;
    ll run = 0;
    for (int i = 0; i < penalty.size(); ++i) {
        p = (p + run + penalty[i]) % m;
        run = (run + penalty[i]) % m;
    }

    cout << penalty.size() << " " << p << endl;
}
