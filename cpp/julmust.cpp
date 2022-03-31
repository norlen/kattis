#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int l = 0;
    int r;
    cin >> r;

    string answer;
    int day = 1;
    while (true) {
        int m = l + (r - l) / 2;
        int total = m * day;
        // cout << m << endl;
        cout << total << "\n" << flush;
        cin >> answer;
        if (answer == "exact") {
            break;
        }
        if (answer == "less") {
            r = m - 1;
        } else {
            l = m + 1;
        }
        day += 1;
    }
}
