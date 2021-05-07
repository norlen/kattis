#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string last, b, a;
    cin >> last >> b;
    a.resize(m);
    
    for (int i = 0; i < n; ++i) {
        a[a.length() - i - 1] = last[last.length() - i - 1];
    }

    for (int i = 0; i < m-n; ++i) {
        int d = b[b.length() - i - 1] - a[a.length() - i - 1];
        a[a.length() - last.length() - i - 1] = 'a' + (d + 26) % 26;
    }
    cout << a << endl;
}