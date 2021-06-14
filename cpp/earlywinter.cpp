#include <iostream>

using namespace std;

int main() {
    int n, d, c;
    cin >> n >> d;

    int i = 0;
    for (; i < n; ++i) {
        cin >> c;
        if (c <= d) break;
    }

    if (i == n) {
        cout << "It had never snowed this early!\n";
    } else {
        cout << "It hadn't snowed this early in " << i << " years!\n";
    }
}