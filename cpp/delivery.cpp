#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n, a;
    cin >> n >> a;

    // First are negative, second are positive.
    vector<vector<pair<int,int>>> l(2, vector<pair<int,int>>());
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a < 0) {
            l[0].push_back({a, b});
        } else {
            l[1].push_back({a, b});
        }
    }
    sort(l[0].rbegin(), l[0].rend());
    sort(l[1].begin(), l[1].end());

    ll dist = 0;
    for (int j = 0; j < 2; ++j) {
        int i = l[j].size() - 1;
        int amount = a;
        while (i >= 0) {
            if (amount == a) {
                // If we just started the route, add distance.
                int d = abs(l[j][i].first) * 2;
                dist += d;
            }
            
            // Hand out letters.
            l[j][i].second -= amount;
            if (l[j][i].second > 0) {
                // If we still have letters to hand out, reset amount.
                amount = a;
            } else {
                // If we handed out all to this location, hand out the rest
                // on the way back.
                amount = 0 - l[j][i].second;
                --i;
            }
        }
    }
    cout << dist << endl;
}
