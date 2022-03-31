#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;

    int ops = 0;
    if (a == b) {
        cout << "0" << endl;
        return 0;
    } else {
        while (a > b) {
            if (a % 2 == 1) {
                ops++;
                a++;
            }
            ops++;
            a /= 2;
        }
    }
    cout << ops + b-a << endl;
}
