#include <iostream>

using namespace std;

int main() {
    int n, T, t;
    cin >> n >> T;

    int i;
    for (i = 0; i < n; ++i) {
        cin >> t;
        T -= t;
        if (T < 0) break;
    }

    cout << i << endl;
}