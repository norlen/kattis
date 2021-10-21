#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    int s0 = 0, s1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        s0 += m;
    }
    for (int i = 0; i < n-1; ++i) {
        cin >> m;
        s1 += m;
    }
    cout << s0-s1 << endl;
}
