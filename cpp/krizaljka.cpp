#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    // Output: a horizontal, b vertical.
    // Where: first letter in a, also in b.
    pair<int,int> idx = {0,0};
    bool done = false;
    for (int i = 0; i < a.length() && !done; ++i) {
        for (int j = 0; j < b.length(); ++j) {
            if (a[i] == b[j]) {
                idx = {i, j};
                done = true;
                break;
            }
        }
    }

    for (int i = 0; i < b.length(); ++i) {
        if (idx.second == i) {
            cout << a;
        } else {
            for (int j = 0; j < a.length(); ++j) {
                cout << (idx.first == j ? b[i] : '.');
            }
        }
        cout << endl;
    }
}