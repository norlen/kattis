#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 5> a;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    while (true) {
        for (int i = 0; i < a.size()-1; ++i) {
            if (a[i] > a[i+1]) {
                swap(a[i+1], a[i]);
                cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << endl;
            }
        }

        if (a[0] == 1 && a[1] == 2 && a[2] == 3 & a[3] == 4 && a[4] == 5) break;
    }
}