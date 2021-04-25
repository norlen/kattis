#include <iostream>

using namespace std;

int main() {
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;

    for (int i = 0; i < r; ++i) {
        string in;
        cin >> in;
        string out;
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < zc; ++k) {
                out.push_back(in[j]);
            }
        }
        for (int j = 0; j < zr; ++j) {
            cout << out << endl;
        }
    }
}