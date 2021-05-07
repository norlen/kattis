#include <iostream>

using namespace std;

int main() {
    while (true) {
        int w, l, n;
        cin >> w >> l;
        if (w == 0 && l == 0) break;
        cin >> n;

        int y = 0, x = 0, ay = 0, ax = 0;
        for (int i = 0; i < n; ++i) {
            // moves: u/d -> length, l/r -> width.
            // postive direction: up & right. i.e. (0,0) bot-left
            char dir;
            int dist;
            cin >> dir >> dist;
            switch (dir) {
                case 'u': {
                    y += dist;
                    ay = min(l-1, ay + dist);
                    break;
                }
                case 'd': {
                    y -= dist;
                    ay = max(0, ay - dist);
                    break;
                }
                case 'r': {
                    x += dist;
                    ax = min(w-1, ax + dist);
                    break;
                }
                case 'l': {
                    x -= dist;
                    ax = max(0, ax - dist);
                    break;
                }
            }
        }
        cout << "Robot thinks " << x << " " << y << endl;
        cout << "Actually at " << ax << " " << ay << endl << endl;
    }
}