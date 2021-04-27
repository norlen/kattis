#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    int prev = 0;
    bool gj = true;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        if (n - 1 != prev) {
            gj = false;
            for (int j = prev+1; j < n; ++j) cout << j << endl;
        }
        prev = n;
    }
    if (gj) {
        cout << "good job\n";
    }
}