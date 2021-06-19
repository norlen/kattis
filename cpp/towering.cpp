#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    int h[6];
    int th[2];
    for (int i = 0; i < 6; ++i) cin >> h[i];
    for (int i = 0; i < 2; ++i) cin >> th[i];

    bool picked[6] = { 0, 0, 0, 0, 0, 0 };
    bool done = false;
    for (int i = 0; i < 6 && !done; ++i) {
        for (int j = i+1; j < 6 && !done; ++j) {
            for (int k = j+1; k < 6 && !done; ++k) {
                if (h[i]+h[j]+h[k] == th[0]) {
                    picked[i] = true;
                    picked[j] = true;
                    picked[k] = true;
                    done = true;
                }
            }
        }
    }

    vector<int> t[2];
    for (int i = 0; i < 6; ++i) {
        int j = picked[i] ? 0 : 1;
        t[j].push_back(h[i]);
    }
    for (int i = 0; i < 2; ++i) {
        sort(t[i].rbegin(), t[i].rend());
        for (auto n : t[i]) {
            cout << n <<  " ";
        }
    }
    cout << endl;
}