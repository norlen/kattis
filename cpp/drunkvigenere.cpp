#include <iostream>

using namespace std;

int main() {
    string c, k, d;
    cin >> c >> k;

    for (int i = 0; i < k.length(); ++i) {
        int ci = c[i] - 'A';
        int ki = k[i] - 'A';
        int di = (i % 2 == 0) ? (ci - ki) : (ci + ki);
        if (di < 0) di += 26;
        d.push_back((di % 26) + 'A');
    }
    cout << d << endl;
}