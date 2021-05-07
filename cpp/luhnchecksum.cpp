#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        string n;
        cin >> n;
        int s = 0;
        for (int i = 0; i < n.length(); ++i) {
            int ind = n.length() - i - 1;
            int d = n[ind] - '0';
            if (i % 2 == 1) {
                d *= 2;
                if (d > 9) {
                    d = (d % 10) + (d/10 % 10);
                }
            }
            s += d;
        }
        if (s % 10 == 0) {
            cout << "PASS\n";
        } else {
            cout << "FAIL\n";
        }
    }
}