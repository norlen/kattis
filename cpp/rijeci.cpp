#include <iostream>

using namespace std;
/**
 * 0: A             1 0
 * 1: B             0 1
 * 2: BA            1 1
 * 3: BAB           1 2
 * 4: BABBA         2 3
 * 5: BABBABAB      3 5
 * 6: BABBABABBABBA 5 8
 * 
 */
int main() {
    int n;
    cin >> n;
    int a = 1, b = 0;
    for (int i = 0; i < n; ++i) {
        int t = b;
        b = a + b;
        a = t;
    }
    cout << a << " " << b << endl;
}