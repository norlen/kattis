#include <iostream>

using namespace std;

int grid[4][4];
int out[4];

void move(int* d) {
    for (int i = 0; i < 4; ++i) {
        if (d[i] == 0) {
            int c = i;
            while (d[c] == 0 && c != 4) c++;
            if (c != 4) {
                swap(d[i], d[c]);
            } else {
                break;
            }
        }
    }
}

void merge(int* d) {
    move(d);
    for (int i = 1; i < 4; ++i) {
        if (d[i] == d[i-1]) {
            d[i] *= 2;
            d[i-1] = 0;
            ++i;
        }
    }
    move(d);
}

int main() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int v;
            cin >> v;
            grid[i][j] = v;
        }
    }
    int dir;
    cin >> dir;

    // 0, 1, 2, or 3 that denotes a left, up, right, or down
    if (dir == 0) {
        for (int i = 0; i < 4; ++i) {
            int d[4] = { grid[i][0], grid[i][1], grid[i][2], grid[i][3] };
            merge(d);
            grid[i][0] = d[0];
            grid[i][1] = d[1];
            grid[i][2] = d[2];
            grid[i][3] = d[3];
        }
    } else if (dir == 1) {
        for (int j = 0; j < 4; ++j) {
            int d[4] = { grid[0][j], grid[1][j], grid[2][j], grid[3][j] };
            merge(d);
            grid[0][j] = d[0];
            grid[1][j] = d[1];
            grid[2][j] = d[2];
            grid[3][j] = d[3];
        }
    } else if (dir == 2) {
        for (int i = 0; i < 4; ++i) {
            int d[4] = { grid[i][3], grid[i][2], grid[i][1], grid[i][0] };
            merge(d);
            grid[i][3] = d[0];
            grid[i][2] = d[1];
            grid[i][1] = d[2];
            grid[i][0] = d[3];
        }
    } else {
        for (int j = 0; j < 4; ++j) {
            int d[4] = { grid[3][j], grid[2][j], grid[1][j], grid[0][j] };
            merge(d);
            grid[3][j] = d[0];
            grid[2][j] = d[1];
            grid[1][j] = d[2];
            grid[0][j] = d[3];
        }
    }

    for (int i = 0; i < 4; ++i) {
        cout << grid[i][0] << " " << grid[i][1] << " " << grid[i][2] << " " << grid[i][3] << endl;
    }
}