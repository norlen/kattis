#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];

    int ans = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        int a = w[i];
        int b = w[(i+n-2) % n];
        ans = min(ans, a+b);
    }
    cout << ans << endl;
}
