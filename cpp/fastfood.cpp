#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int c = 0; c < t; ++c) {
        int n, m, k, cash;
        cin >> n >> m;

        vector<pair<int, vector<int>>> prizes(n);
        for (int i = 0; i < n; ++i) {
            cin >> k;
            vector<int> ks(k);
            for (int j = 0; j < k; ++j) cin >> ks[j];
            cin >> cash;

            prizes[i] = { cash, ks };
        }

        vector<int> tickets(m);
        for (int i = 0; i < m; ++i) cin >> tickets[i];

        // Prizes all have different tickets, so they can be collected in any order.
        int total = 0;
        for (pair<int, vector<int>>& prize : prizes) {
            int max_collections = INT32_MAX;
            for (auto k : prize.second) {
                max_collections = min(max_collections, tickets[k-1]);
            }
            for (auto k : prize.second) {
                tickets[k-1] -= max_collections;
            }
            total += max_collections * prize.first;
        }

        cout << total << endl;
    }
}