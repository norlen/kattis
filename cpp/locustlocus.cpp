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
    int k, y, f, s;
    cin >> k;
    int fy = INT32_MAX;

    for (int i = 0; i < k; ++i) {
        cin >> y >> f >> s;
        int lcm = f*s / gcd(f, s);
        if (y+lcm < fy) {
            fy = y+lcm;
        }
    }
    cout << fy << endl;
}