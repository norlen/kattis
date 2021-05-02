#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    while (x > 9) {
        int t = x;
        int p = 1;
        while (t > 0) {
            int f = t % 10;
            if (f != 0) p *= f;
            t /= 10;
        }
        x = p;
    }
    cout << x << endl;
}