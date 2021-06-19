#include <iostream>
#include <array>

using namespace std;

int main() {
    int n, r = 0, s = 0;
    string a, b;
    cin >> n >> a >> b;

    array<int, 26> l;
    for (int i = 0; i < l.size(); ++i) l[i] = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            l[a[i] - 'A']++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            r++;
        } else if (l[b[i] - 'A'] > 0) {
            l[b[i] - 'A']--;
            s++;
        }
    }

    cout << r << " " << s << endl;
}