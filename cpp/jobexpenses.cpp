#include <iostream>

using namespace std;

int main() {
    int n, a;
    cin >> n;

    int e = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a < 0) {
            e += -a;
        }
    }
    cout << e << endl;
}