#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int e = 31;
    while (((n >> e) & 0x1) == 0) --e; // find first 1

    int ans = 0;
    for (int i = 0; i <= e; ++i) {
        int b = (n >> i) & 0x1;
        ans = ans << 1 | b;
    }
    cout << ans << endl;
}