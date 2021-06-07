#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int k = 0; k < n; ++k) {
        string in;
        cin >> in;

        int l = in.length();
        int sqm = static_cast<int>(ceil(sqrt(l)));

        vector<vector<char>> g(sqm);
        for (int i = 0; i < sqm; ++i) g[i] = vector<char>(sqm);

        int m = 0;
        for (int j = sqm-1; j >= 0; --j) {
            for (int i = 0; i < sqm; ++i) {
                g[i][j] = m < in.length() ? in[m] : '*';
                m++;
            }
        }

        for (int i = 0; i < sqm; ++i) {
            for (int j = 0; j < sqm; ++j) {
                if (g[i][j] != '*') cout << g[i][j];
            }
        }
        cout << endl;
    }
}