#include <iostream>

using namespace std;

int main() {
    int n, c;
    cin >> n;

    int p[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
        cin >> c;
        for (int j = 0; j < 4; ++j) {
            p[j/2] += 1 - c % 10;
            c /= 10;
        }
    }
    int swords = min(p[0], p[1]) / 2;
    cout << swords << " " << p[1] - swords*2 << " " << p[0] - swords*2 << endl;
}