#include <iostream>
#include <vector>

using namespace std;

struct Piece {
    int n;
    int w;
    vector<int> hs;
};

int main() {
    vector<Piece> pieces = {
        { 1, 1, { 0 }},
        { 1, 4, { 0, 0, 0, 0 }},
        { 2, 2, { 0, 0 }},
        { 3, 3, { 0, 0, 1 }},
        { 3, 2, { 0, -1 }},
        { 4, 3, { 0, -1, -1 }},
        { 4, 2, { 0, 1 }},
        { 5, 3, { 0, 0, 0 }},
        { 5, 3, { 0, -1, 0 }},
        { 5, 2, { 0, -1 }},
        { 5, 2, { 0, 1 }},
        { 6, 3, { 0, 0, 0 }},
        { 6, 3, { 0, 1, 1 }},
        { 6, 2, { 0, -2 }},
        { 6, 2, { 0, 0 }},
        { 7, 3, { 0, 0, 0 }},
        { 7, 3, { 0, 0, -1 }},
        { 7, 2, { 0, 2 }},
        { 7, 2, { 0, 0 }},
    };

    int c, p;
    cin >> c >> p;

    vector<int> heights(c);
    for (int i = 0; i < c; ++i) cin >> heights[i];

    int ways = 0;
    for (auto& piece : pieces) {
        if (piece.n != p) continue;

        for (int j = 0; j < heights.size() - piece.w + 1; ++j) {
            bool ok = true;
            int base = heights[j] + piece.hs[0];
            for (int k = 0; k < piece.w; ++k) {
                if (heights[j+k] != base + piece.hs[k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ways++;
        }
    }

    cout << ways << endl;
}