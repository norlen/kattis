#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    int m = n / 100;
    pair<int,int> options = {(m - 1) * 100 + 99, m * 100 + 99};
    pair<int,int> diffs = {abs(options.first - n), abs(options.second - n)};
    if (m != 0 && diffs.first < diffs.second) {
        cout << options.first << endl;
    } else {
        cout << options.second << endl;
    }
}
