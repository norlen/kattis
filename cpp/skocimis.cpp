#include <iostream>

using namespace std;

int main() {
    int p[3];
    cin >> p[0] >> p[1] >> p[2];

    int moves = 0;
    while (p[1]+1 != p[2]) {
        moves++;
        p[0] = p[1]+1;
        swap(p[0], p[1]);
    }
    cout << moves << endl;
}