#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int r, c;
        cin >> r >> c;
        string in;
        vector<string> g;
        for (int j = 0; j < r; ++j) {
            cin >> in;
            g.push_back(in);
        }

        cout << "Test " << i+1 << endl;
        for (int j = r-1; j >= 0; --j) {
            for (int k = c-1; k >= 0; --k) {
                cout << g[j][k];
            }
            cout << endl;
        }
    }
}