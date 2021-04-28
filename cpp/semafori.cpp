#include <iostream>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    int time = 0;
    int wait_time = 0;
    int prev_dist = 0;
    int d, r, g;
    for (int i = 0; i < n; ++i) {
        cin >> d >> r >> g;
        
        time += d - prev_dist;

        int s = r + g;
        int a = time % s; // red at start. (0, r] = RED, [r, g] = GREEN
        if (a >= 0 && a < r) {
            //cerr << "waiting " << r - a << " secs\n";
            time += r - a;
            wait_time += r - a;
        }
        prev_dist = d;
    }
    cout << l + wait_time << endl;
}