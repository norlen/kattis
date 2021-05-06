#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    sort(m.rbegin(), m.rend());

    int a = 0, b = 0;
    for (int i = 0; i < m.size(); ++i) {
        if (i % 2 == 0) {
            a += m[i];
        } else {
            b += m[i];
        }
    }
    cout << a << " " << b << endl;
}