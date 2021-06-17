#include <iostream>
#include <vector>
#include <array>

using namespace std;

array<char, 2> pattern = {'#', '.'};

int main() {
    int m, n, u, l, r, d;
    cin >> m >> n >> u >> l >> r >> d;

    vector<string> words(m);
    for (int i = 0; i < m; ++i) {
        cin >> words[i];
    }

    int w = n + l + r;
    int h = m + u + d;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i < u || i >= (u+m) || (j < l || j >= (l+n))) {
                cout << pattern[(i%2 + j) % 2];
            } else {
                cout << words[i-u][j-l];
            }
        }
        cout << endl;
    }
}