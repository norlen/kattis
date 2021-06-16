#include <iostream>

using namespace std;

int main() {
    string a, b;
    char op;
    cin >> a >> op >> b;
    if (b.length() > a.length()) swap(a, b);

    if (op == '*') {
        for (int i = 0; i < b.length()-1; ++i) {
            a.push_back('0');
        }
    } else if (a.length() != b.length()) {
        size_t idx = a.length() - b.length();
        a[idx] = '1';
    } else {
        a[0] = '2';
    }
    cout << a << endl;
}