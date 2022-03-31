#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    
    cin >> n;
    vector<int> price_teas(n);
    for (int i = 0; i < n; ++i) cin >> price_teas[i];

    cin >> m;
    vector<int> price_toppings(m);
    for (int i = 0; i < m; ++i) cin >> price_toppings[i];

    int lowest_price = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int match;
            cin >> match;

            int price = price_teas[i] + price_toppings[match-1];
            // cout << "Tea=" << i << ", topping=" << match-1 << ", total_cost=" << price << endl;
            lowest_price = min(lowest_price, price);
        }
    }

    int money;
    cin >> money;
    // cout << "Lowest cost=" << lowest_price << ", money=" << money << endl;

    cout << max(0, (money / lowest_price)-1) << endl;
}
