#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> g(4);
    for (int i = 0; i < 4; ++i) cin >> g[i];

    int d = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (g[i][j] == '.') continue;
            int idx = g[i][j] - 'A';
            int x = idx % 4;
            int y = idx / 4;
            d += abs(j - x) + abs(i - y);
        }
    }
    cout << d << endl;
}