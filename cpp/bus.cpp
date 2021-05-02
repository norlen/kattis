#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, p = 0;
        cin >> n;
        while (n > 0) {
            p = p * 2 + 1;
            n--;
        }
        cout << p << endl;
    }
}