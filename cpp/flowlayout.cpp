#include <iostream>

using namespace std;

int main() {
    int m, w, h;
    while (true) {
        cin >> m;
        if (m == 0) break;

        int cw = 0, ch = 0;
        int th = 0, mw = 0;
        while (true) {
            cin >> w >> h;
            if (w == -1 && h == -1) break;
            if (cw + w <= m) {
                cw += w;
                ch = max(ch, h);
            } else {
                th += ch;
                cw = w;
                ch = h;
            }
            mw = max(mw, cw);
        }
        th += ch;

        cout << mw << " x " << th << endl;
    }
}