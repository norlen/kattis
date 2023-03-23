#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string a, b;
    cin >> a >> b;
    a += b;
    sort(a.begin(), a.end());
    cout << a << endl;
}
