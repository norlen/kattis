#include <iostream>

using namespace std;

int main() {
    int a, b, c, n, s = 0;
    cin >> a >> b >> c >> n;
    s = a + b + c;

    // Problem set of exactly n problems
    // At least 1 easy, med, hard.
    // implicitly: at least three problems.
    if (n < 3 || s < n || a == 0 || b == 0 || c == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}