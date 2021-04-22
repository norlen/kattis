#include <iostream>

using namespace std;

int main() {
    int pieces[6];
    for (int i = 0; i < 6; ++i) {
        cin >> pieces[i];
    }
    int expected[6] = { 1, 1, 2, 2, 2, 8 };

    for (int i = 0; i < 5; ++i) {
        cout << expected[i] - pieces[i] << " ";
    }
    cout << expected[5] - pieces[5] << endl;
}