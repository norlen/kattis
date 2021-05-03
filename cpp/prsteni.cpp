#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int main() {
    int n, b;
    cin >> n >> b;

    for (int i = 0; i < n-1; ++i) {
        int c;
        cin >> c;
        int g = gcd(b, c);
        int d = b / g;
        int lcd = (c*b)/g;
        cout << d << "/" << lcd/b << endl;
    }
}