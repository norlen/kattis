#include <iostream>

using namespace std;

int main() {
    int h, w, n, in;
    cin >> h >> w >> n;

    int ch = 0, cw = 0;
    bool not_ok = false;
    for (int i = 0; i < n && ch < h; ++i) {
        cin >> in;
        cw += in;
        if (cw > w) {
            not_ok = true;
            break;
        } else if (cw == w) {
            ch++;
            cw = 0;
        }
    }

    cout << (not_ok || cw != 0 ? "NO\n" : "YES\n");
}