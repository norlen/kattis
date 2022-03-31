#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> cols(n, 0);
    vector<int> rows(n, 0);
    vector<int> diag(2*n-1, 0);
    vector<int> adiag(2*n-1, 0);

    bool notok = false;
    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;

        int pos_d = r + c;
        int pos_ad = n + c - r - 1;

        if (cols[r] == 0 && rows[c] == 0 && diag[pos_d] == 0 && adiag[pos_ad] == 0) {
            cols[r] = 1;
            rows[c] = 1;
            diag[pos_d] = 1;
            adiag[pos_ad] = 1;
        } else {
            notok = true;
            break;
        }
    }

    if (notok) {
        cout << "INCORRECT\n";
    } else {
        cout << "CORRECT\n";
    }
}
