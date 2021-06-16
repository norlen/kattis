#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, n, c;
    cin >> r >> n;

    if (n >= r) {
        cout << "too late\n";
    } else {
        vector<bool> a(r, false);
        for (int i = 0; i < n; ++i) {
            cin >> c;
            a[c-1] = true;
        }
        for (int i = 0; i < r; ++i) {
            if (a[i] == false) {
                cout << i+1 << endl;
                break;
            }
        }
    }
}