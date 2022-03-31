#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll x, y, r;
    cin >> x >> y >> r;

    const pair<int,int> offsets[4] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    for (pair<int,int> o : offsets) {
        cout << x + o.first*r << " " << y + o.second*r << endl;
    }
}
