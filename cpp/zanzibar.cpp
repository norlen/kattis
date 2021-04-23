#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int prev, curr;
        cin >> curr;

        int import = 0;
        while (curr != 0) {
            prev = curr;
            cin >> curr;

            int additional = curr - prev*2; // safe if curr == 0.
            import += max(0, additional);
        }
        cout << import << endl;
    }
}