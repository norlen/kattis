#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> idx_to_next(n, -1);
    int idx_last_to_first = -1;
    int has_next_count = 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        if (u+1 == v) {
            idx_to_next[u-1] = i + 1;
            has_next_count++;
        }
        if (u == 1 && v == n) {
            idx_last_to_first = i + 1;
        }
    }

    if (idx_last_to_first == -1 || has_next_count < n-1) {
        cout << "impossible" << endl;
        return 0;
    }

    for (int i = 0; i < idx_to_next.size()-1; ++i) {
        cout << idx_to_next[i] << endl;
    }
    cout << idx_last_to_first << endl;
}
