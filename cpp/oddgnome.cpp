#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int num, prev, curr, king = -1;
        cin >> num >> prev;
        for (int j = 1; j < num; ++j) {
            cin >> curr;
            if (king == -1 && curr != prev + 1) {
                king = j+1;
            }
            prev = curr;
        }
        cout << king << endl;
    }
}