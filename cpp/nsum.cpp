#include <iostream>

using namespace std;

int main() {
    int n, m, s = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        s += m;
    }
    cout << s << endl;
}
