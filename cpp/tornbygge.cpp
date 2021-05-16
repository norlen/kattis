#include <iostream>

using namespace std;

int main() {
    int n, c, prev = 0;
    cin >> n;

    int towers = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c > prev) {
            towers++;
        }
        prev = c;
    }
    cout << towers << endl;
}