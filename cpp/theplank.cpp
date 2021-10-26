#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Plank lengths: 1, 2, 3.
    // Let P(n) be the ways to assemble a plank of length n.
    // - P(1) = 1
    // - P(2) = 2 (one 2, two 1)
    // - P(3) = 4 (one 3, 1+2, 2+1, 1+1+1)
    // - P(n) = P(n-1) + P(n-2) + P(n-3)
    int a = 1, b = 2, c = 4;
    for (int i = 4; i <= n; ++i) {
        int t = a + b + c;
        a = b;
        b = c;
        c = t;
    }
    
    if (n == 1) {
        cout << a << endl;
    } else if (n == 2) {
        cout << b << endl;
    } else {
        cout << c << endl;
    }
}