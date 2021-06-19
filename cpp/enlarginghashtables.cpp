#include <iostream>

using namespace std;
using ll = long long;

bool is_prime(ll n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ll n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        ll m = 2*n;  
        while (!is_prime(m)) {
            m++;
        }

        cout << m;
        if (!is_prime(n)) {
            cout << " (" << n << " is not prime)";
        }
        cout << endl;
    }
}