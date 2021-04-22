#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < a.length() && i < b.length(); ++i) {
        if (a[i] != b[i]) {
            if (a[i] > b[i]) {
                cout << a << endl;
            } else {
                cout << b << endl;
            }
            break;
        }
    }
}