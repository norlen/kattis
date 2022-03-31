#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void move_f(int& x, int& y, int& dir) {
    if (dir == 0) {
        x++;
    } else if (dir == 1) {
        y++;
    } else if (dir == 2) {
        x--;
    } else {
        y--;
    }
}

int main() {
    int T;
    cin >> T;

    cout << T << endl;
    for (int t = 0; t < T; ++t) {
        string path;
        cin >> path;

        int x = 0, y = 0, dir = 0;
        int maxW = 0, maxH = 0;
        int minW = 0, minH = 0;
        for (auto ch : path) {
            switch (ch) {
                case 'F': {
                    move_f(x, y, dir);
                    break;
                }
                case 'B': {
                    dir = (dir + 2) % 4;
                    move_f(x, y, dir);
                    break;
                }
                case 'R': {
                    dir = (dir + 1) % 4;
                    move_f(x, y, dir);
                    break;
                }
                case 'L': {
                    dir = (dir + 3) % 4;
                    move_f(x, y, dir);
                    break;
                }
            }
            maxW = max(maxW, x);
            minW = min(minW, x);
            maxH = max(maxH, y);
            minH = min(minH, y);
        }

        int width = (maxW-minW) + 2;
        int height = (maxH-minH) + 3;

        vector<string> grid(height, string(width, '#'));
        int startY = -minH + 1;

        x = 0, y = startY, dir = 0;
        grid[y][x] = '.';
        for (auto ch : path) {
            switch (ch) {
                case 'F': {
                    move_f(x, y, dir);
                    break;
                }
                case 'B': {
                    dir = (dir + 2) % 4;
                    move_f(x, y, dir);
                    break;
                }
                case 'R': {
                    dir = (dir + 1) % 4;
                    move_f(x, y, dir);
                    break;
                }
                case 'L': {
                    dir = (dir + 3) % 4;
                    move_f(x, y, dir);
                    break;
                }
            }
            grid[y][x] = '.';
        }

        cout << height << " " << width << endl;
        for (int i = 0; i < grid.size(); ++i) {
            cout << grid[i] << endl;
        }
    }
}