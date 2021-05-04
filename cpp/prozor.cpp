#include <iostream>

using namespace std;

int main() {
    int r, s, k;
    cin >> r >> s >> k;
    string in;
    getline(cin, in);

    char grid[101][101];
    for (int i = 0; i < r; ++i) {
        getline(cin, in);
        for (int j = 0; j < s; ++j) {
            grid[i][j] = in[j];
        }
    }

    int max_flies = (k-2)*(k-2);
    int msf = 0;
    int sr, sc;
    for (int i = 0; i < r-k+1; ++i) {
        for (int j = 0; j < s-k+1; ++j) {
            // explore.
            int flies = 0;
            for (int m = 1; m < k-1; ++m) {
                for (int n = 1; n < k-1; ++n) {
                    if (grid[i+m][j+n] == '*') {
                        flies++;
                    }
                }
            }
            if (flies > msf) {
                msf = flies;
                sr = i;
                sc = j;
            }
        }
    }

    cout << msf << endl;
    int er = sr + k - 1;
    int ec = sc + k - 1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            if ((i == sr && j == sc) || (i == sr && j == ec) || (i == er && j == sc) || (i == er && j == ec)) {
                cout << "+";
            } else if ((i > sr && i < er) && (j == sc || j == ec)) {
                cout << "|";
            } else if ((j > sc && j < ec) && (i == sr || i == er)) {
                cout << "-";
            } else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }
}