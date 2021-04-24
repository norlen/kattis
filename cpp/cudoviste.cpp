#include <iostream>
#include <vector>

using namespace std;

char grid[50][50];

int count(int i, int j, char v) {
    return (grid[i    ][j    ] == v) +
           (grid[i    ][j + 1] == v) +
           (grid[i + 1][j    ] == v) +
           (grid[i + 1][j + 1] == v);
}

int main() {
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; ++i) {
        string s;
        cin >> s;
        copy(s.begin(), s.end(), grid[i]);
    }

    int counts[5] = {0};
    for (int i = 0; i < r-1; ++i) {
        for (int j = 0; j < c-1; ++j) {
            if (count(i, j, '#')) continue;
            counts[count(i, j, 'X')]++;
        }
    }

    for (int i = 0; i < 5; ++i) {
        cout << counts[i] << endl;
    }
}