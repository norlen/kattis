#include <iostream>

using namespace std;

int main() {
    int s, v1, v2;
    cin >> s >> v1 >> v2;

    int c1 = s / v1;
    int c2 = (s % v1) / v2;
    int s2 = s - (c1*v1 + c2*v2);

    while (c1 > 0) {
        if (c1*v1 + c2*v2 == s) {
            break;
        }
        s2 += v1;
        c1--;
        c2 += s2 / v2;
        s2 -= (s2 / v2) * v2;
    }

    if (c1*v1 + c2*v2 == s) {
        cout << c1 << " " << c2 << endl;
    } else {
        cout << "Impossible\n";
    }
}