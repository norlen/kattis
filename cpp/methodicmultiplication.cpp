#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int sa = 0, sb = 0;
    for (auto ch : a) {
        if (ch == 'S') sa++;
    }
    for (auto ch : b) {
        if (ch == 'S') sb++;
    }

    for (int i = 0; i < sa*sb; ++i) {
        cout << "S(";
    }
    cout << "0";
    for (int i = 0; i < sa*sb; ++i) {
        cout << ")";
    }
    cout << endl;
}