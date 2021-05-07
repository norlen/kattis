#include <iostream>
#include <vector>

using namespace std;

int main() {
    int stars;
    cin >> stars;

    cout << stars << ":\n";
    int max_per_row = stars/2 + stars%2;
    for (int r0 = 2; r0 <= max_per_row; ++r0) {
        // A flag pattern is visually appealing if it satisfies the following conditions:
        // 1. Every other row has the same number of stars.
        // 2. Adjacent rows differ by no more than one star.
        // 3. The first row cannot have fewer stars than the second row.
        for (int r1 = r0-1; r1 <= r0; ++r1) {
            // Two combinations for each r0 for (2) & (3).

            // Star example: 50 stars: s
            // * * * * * * 6 stars: a stars
            //  * * * * *  5 stars: b stars
            // * * * * * *
            //  * * * * *
            // * * * * * *
            //  * * * * *
            // * * * * * *
            //  * * * * *
            // * * * * * *
            // So we have to make sure this holds.
            // s = an + bn || a(n+1) + bn
            //   = n(a+b)  || an + a + bn
            //   = n(a+b)  || n(a+b) + a
            //
            // n = s/(a+b) || (s - a)/(a+b)
            
            // Check if n is an integer.
            if ((stars % (r0+r1) == 0) || ((stars - r0) % (r0 + r1) == 0)) {
                cout << r0 << "," << r1 << endl;
            }
        }
    }
}