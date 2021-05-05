#include <iostream>

using namespace std;

const int PLAYERS = 8;
const int EXPLODES = 60 * 3 + 30; // 3 mins 30 secs

int main() {
    int k, n;
    cin >> k >> n;
    k -= 1; // zero index players.

    int ct = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        char a;
        cin >> t >> a;

        ct += t;
        if (ct >= EXPLODES) break;
        if (a == 'T') {
            k = (k + 1) % PLAYERS;
        }
    }
    cout << k+1 << endl;
}