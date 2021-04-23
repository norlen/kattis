#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;

        cout << a << endl << b << endl;
        for (int j = 0; j < a.length(); ++j) {
            cout << (a[j] == b[j] ? '.' : '*');
        }
        cout << endl << endl;
    }
}