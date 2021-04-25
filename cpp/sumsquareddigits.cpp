#include <iostream>
#include <inttypes.h>

using namespace std;

int main() {
    int p;
    cin >> p;

    for (int i = 0; i < p; ++i) {
        uint32_t k, b, n;
        cin >> k >> b >> n;
        long long out = 0;
        while (n > 0) {
            uint32_t d = n % b;
            out += d*d;
            n /= b;
        }
        cout << k << " " << out << endl;
    }
}