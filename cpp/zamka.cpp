#include <iostream>

using namespace std;

int digit_sum(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    int l, d, x;
    cin >> l >> d >> x;

    int ans = l;
    while (true) {
        if (digit_sum(ans) == x) {
            cout << ans << endl;
            break;
        }
        ans++;
    }

    ans = d;
    while (true) {
        if (digit_sum(ans) == x) {
            cout << ans << endl;
            break;
        }
        ans--;
    }
}