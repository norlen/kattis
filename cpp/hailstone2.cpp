#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n, l = 1;
    cin >> n;
    while (n > 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n*3 + 1;
        }
        l++;
    }
    cout << l << endl;
}
