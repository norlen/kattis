#include <iostream>

using namespace std;

int main() {
    int n, c;
    cin >> n;

    int min = INT32_MAX;
    int i = 0;
    for (int j = 0; j < n; ++j) {
        cin >> c;
        if (c < min) {
            min = c;
            i = j;
        }
    }
    cout << i << endl;
}