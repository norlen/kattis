#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (b.length() > a.length()) swap(a, b);

    int c = a.length()-1;
    int d = b.length()-1;
    int carry = 0;
    while (c >= 0 && (d >= 0 || carry)) {
        int r = (a[c] - '0') + carry;
        carry = 0;
        if (d >= 0) {
            r += (b[d] - '0');
            d--;
        }

        if (r >= 10) {
            r -= 10;
            carry = 1;
        }
        a[c] = r + '0';

        c--;
    }

    cout << (carry > 0 ? "1" : "") << a << endl;
}