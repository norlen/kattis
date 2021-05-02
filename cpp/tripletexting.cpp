#include <iostream>

using namespace std;

bool matches(string a, int ls, int rs, int len) {
    for (int i = 0; i < len; ++i) {
        if (a[ls+i] != a[rs+i]) return false;
    }
    return true;
}

int main() {
    string in;
    cin >> in;
    int n = in.length() / 3;

    // check 0-1, then 0-2, if neither match 0 is wrong.
    if (matches(in, 0, n, n)) {
        cout << in.substr(0, n) << endl;
        return 0;
    } else if (matches(in, 0, n*2, n)) {
        cout << in.substr(0, n) << endl;
    } else {
        cout << in.substr(n, n) << endl;
    }
}