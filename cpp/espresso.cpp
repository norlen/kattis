#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, s;
    cin >> n >> s;

    string in;
    int current_water = s;
    int times_refilled = 0;
    for (int i = 0; i < n; ++i) {
        cin >> in;
        bool is_latte = in.size() == 2;
        int water_required = in[0] - '0' + (is_latte ? 1 : 0);

        if (water_required > current_water) {
            current_water = s;
            times_refilled += 1;
        }
        current_water -= water_required;
    }
    cout << times_refilled << endl;
}
