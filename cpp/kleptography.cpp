#include <iostream>
// TODO!
using namespace std;

int main() {
    int n, m;
    char ch;
    cin >> n >> m;

    string a_last, b, a;
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        a_last.push_back(ch);
    }
    for (int i = 0; i < m; ++i) {
        cin >> ch;
        b.push_back(ch);
    }
    cout << "a_last: [" << a_last << "]" << endl;
    cout << "b     : [" << b << "]" << endl;
}