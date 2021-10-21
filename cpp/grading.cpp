#include <iostream>

using namespace std;

int main() {
    const char* grades = "ABCDEF";
    int g[6], c;
    g[5] = 0;
    for (int i = 0; i < 5; ++i) cin >> g[i];
    cin >> c;
    for (int i = 0; i < 6; ++i) {
        if (c >= g[i]) {
            cout << grades[i] << endl;
            break;
        }
    }
}