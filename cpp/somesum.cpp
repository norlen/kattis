#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // So we'll have x + (x+1) + (x+2) + ..., with n terms.
    // so we'll write it as n*x + sum(zero to n-1).
    // And check with x either being even or odd.
    int add = n*(n-1) / 2;
    int s0 = (2*n + add) % 2;
    int s1 = (3*n + add) % 2;

    if (s0 == 0 && s1 == 0) cout << "Even\n";
    else if (s0 == 1 && s1 == 1) cout << "Odd\n";
    else cout << "Either\n";
}