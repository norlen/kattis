#include <iostream>

using namespace std;

int main() {
    // Matrices are in the format:
    // A = [a b]
    //     [c d]
    // Inverse for 2x2 matrix is:
    // A^-1 = 1 / det(A) * [d -b]
    //                     [-c a]
    int a, b, c, d;
    int cc = 1;
    while (cin >> a >> b >> c >> d) {
        int det = a*d - c*b;
        int s = 1 / det;
        cout << "Case " << cc << ":\n";
        cout << s*d << " " << s*(-b) << endl;
        cout << s*(-c) << " " << s*a << endl;
        cc++;
    }
}
