#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int x;
    cin >> x;
    if (x < 1) {
        cout << "0\n";
        return 0;
    }

    string in;
    cin >> in;

    int let_in = 0;
    int m = 0;
    int w = 0;
    for (int i = 0; i < in.size(); ++i) {
        if (in[i] == 'M') {
            m++;
        }
        if (in[i] == 'W') {
            w++;
        }
        int d = abs(m-w);
        if (d > x) {
            if (i < in.size()-1 && in[i+1] != in[i]) {
                // ok take from next.
                let_in ++;
            } else {
                break;
            }
        } else {
            let_in++;
        }
    }

    cout << let_in << endl;
}
