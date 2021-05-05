#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    bool f = false;
    while (true) {
        int r, c;
        cin >> r >> c;
        if (r == 0 && c == 0) break;
        if (f) cout << endl;
        f = true;

        vector<string> ss(c);
        string in;
        for (int i = 0; i < r; ++i) {
            cin >> in;
            for (int j = 0; j < c; ++j) {
                ss[j].push_back(in[j]);
            }
        }
        
        for (int i = r-1; i >= 0; --i) {
            stable_sort(ss.begin(), ss.end(), [i](const auto& lhs, const auto& rhs) {
                return tolower(lhs[i]) < tolower(rhs[i]);
            });
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << ss[j][i];
            }
            cout << endl;
        }
    }
}