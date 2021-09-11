#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    vector<vector<int>> image(h);
    for (int i = 0; i < h; ++i) {
        image[i] = vector<int>(w);
        for (int j = 0; j < w; ++j) {
            cin >> image[i][j];
        }
    }

    vector<vector<int>> kernel(n);
    for (int i = 0; i < n; ++i) {
        kernel[n-i-1] = vector<int>(m);
        for (int j = 0; j < m; ++j) {
            cin >> kernel[n-i-1][m-j-1]; // Flip rows & cols.
        }
    }

    int out_h = h - n + 1;
    int out_w = w - m + 1;
    vector<vector<int>> output(out_h);
    for (int i = 0; i < out_h; ++i) {
        output[i] = vector<int>(out_w);
        for (int j = 0; j < out_w; ++j) {
            // Perform operation.
            int s = 0;
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < m; ++l) {
                    s += image[i+k][j+l] * kernel[k][l];
                }
            }
            output[i][j] = s;
        }
    }

    for (int i = 0; i < output.size(); ++i) {
        for (int j = 0; j < output[i].size(); ++j) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}