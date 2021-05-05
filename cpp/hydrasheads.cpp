#include <iostream>

using namespace std;

int main() {
    while (true) {
        int h, t;
        cin >> h >> t;
        if (h == 0 && t == 0) break;

        // If PyPy cuts off exactly one head, a new head grows immediately. <- useless
        // If PyPy cuts off exactly one tail, two new tails grow immediately.
        // If PyPy cuts off exactly two tails, a new head grows immediately.
        // If PyPy cuts off exactly two heads, nothing happens.

        // Need even amount of heads and zero tails.
        int moves = 0;
        while (!(h % 2 == 0 && t == 0)) {
            // impossible.
            if (t == 0) {
                moves = -1;
                h = 0;
                break;
            }

            if (h >= 2) {
                h -= 2;
            } else if (t % ((2-h)*2) != 0) {
                t += 1;
            } else {
                t -= 2;
                h += 1;
            }
            moves++;
        }
        cout << moves + h/2 << endl;
    }
}