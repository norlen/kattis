#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int p, q, s;
    cin >> p >> q >> s;
    int lcm = abs(p*q)/gcd(p, q);
    if (lcm <= s) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}