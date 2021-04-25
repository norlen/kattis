#include <iostream>

using namespace std;

bool is_appealing(int stars, int r0, int r1) {
    if (r0 + r1 > stars) return false;
    if (r0 + r1 == stars) return true;

    for (int i = 2; r0*i < stars; ++i) {
        int remaining = stars - r0*i;
        for (int j = -1; j < 2; ++j) {
            if ((remaining / (i + j) == r1) && (remaining % (i + j) == 0)) {
                return true;
            }
        }
    }
    return false;
}

bool is_appealing2(int stars, int r0, int r1) {
    int s = r0 + r1;
    int r = stars % s;
    if (r == 0 || r == r0 || r == r1) {
        // cout << r0 << "," << r1 << " OK " << "s: " << s << ", r: " << r << "\n";
        return true;
    }
    // cout << r0 << "," << r1 << " NOT OK " << "s: " << s << ", r: " << r << "\n";
    return false;
}

int main() {
    int n;
    cin >> n;

    int r0 = 2;
    int r1 = 1;

    cout << n << ":\n";
    while (r0 + r1 <= n) {
        if (is_appealing2(n, r0, r1)) {
            cout << r0 << "," << r1 << endl;
        }
        if (r0 - 1 == r1) r1++;
        else r0++;
    }
}