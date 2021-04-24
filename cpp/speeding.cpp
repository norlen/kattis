#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int maxspeed = 0;
    int tprev, dprev;
    cin >> tprev >> dprev;
    for (int i = 1; i < n; ++i) {
        int t, d;
        cin >> t >> d;

        int speed = (d - dprev) / (t - tprev);
        maxspeed = max(maxspeed, speed);

        tprev = t;
        dprev = d;
    }
    cout << maxspeed << endl;
}