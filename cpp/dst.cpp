#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char change; // forwards (F) or backwards (B)
        int d, h, m; // d=change in minutes, h=current hour, m=current min
        cin >> change >> d >> h >> m;

        if (change == 'F') {
            m += d;
            while (m >= 60) {
                m -= 60;
                h++;
            }
            if (h >= 24) {
                h -= 24;
            }
        } else {
            m -= d;
            while (m < 0) {
                m += 60;
                h--;
            }
            if (h < 0) {
                h += 24;
            }
        }
        cout << h << " " << m << endl;
    }
}