#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string a = "N";
    string b = "A";

    int n, k;
    cin >> n >> k;


    for (int i = 2; i < n; ++i) {
        string t = a + b;
        a = b;
        b = t;
        cout << b << endl;
    }

    cout << b[k-1] << endl;
}
