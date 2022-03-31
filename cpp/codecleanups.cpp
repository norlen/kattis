#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, d;
    cin >> n;

    vector<bool> days(365, false);
    for (int i = 0; i < n; ++i) {
        cin >> d;
        days[d-1] = true;
    }

    int dirty = 0;
    int num_pushes = 0;
    int cleanups = 0;
    for (int i = 0; i < days.size(); ++i) {
        if (days[i]) {
            num_pushes += 1;
        }

        dirty += num_pushes;
        if (dirty >= 20 || i == days.size()-1) {
            cleanups += 1;

            dirty = 0;
            num_pushes = 0;
        }
    }

    cout << cleanups << endl;
}
