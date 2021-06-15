#include <iostream>

using namespace std;

const char* out[] = {
    ".#...#...*..",
    "#.#.#.#.*.*.",
    ".X.#.X.*.X.*",
    "#.#.#.#.*.*.",
    ".#...#...*.."
};
const char* first = "..#..";

int main() {
    string in;
    cin >> in;
    size_t m = in.length() * 4;

    int k = 0;
    for (int i = 0; i < 5; ++i) {
        cout << first[i];
        for (int j = 0; j < m; ++j) {
            // Special case since we should never end with *.
            if (i == 2 && j == m-1 && (j % 12) % 7 == 0) {
                cout << '#';
            } else if (i == 2 && out[i][j % 12] == 'X') {
                cout << in[k++];
            } else {
                cout << out[i][j % 12];
            }
        }
        cout << endl;
    }
}