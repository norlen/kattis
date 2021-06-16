#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    array<int, 3> a;
    while (true) {
        cin >> a[0] >> a[1] >> a[2];
        if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;
        sort(a.begin(), a.end());

        cout << ((a[0]*a[0]+a[1]*a[1]) == a[2]*a[2] ? "right\n" : "wrong\n");
    }
}
