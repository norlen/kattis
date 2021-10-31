#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

ll pack(ll u, ll v) {
    return ((u << 32) | v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, u, v, w;
    cin >> n >> m;

    unordered_map<ll, int> e;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        ll k = pack(u, v);
        if (e.count(k) == 0) {
            e.insert({k, 1});
        } else {
            ++e[k];
        }
    }

    cin >> w;
    cin >> u;
    for (int i = 0; i < w; ++i) {
        cin >> v;
        ll k = pack(u, v);
        if (e.count(k) == 0) {
            cout << i + 1 << endl;
            return 0;
        }
        e[k]--;
        if (e[k] == 0) {
            e.erase(k);
        }
        u = v;
    }

    if (e.size() == 0) {
        cout << "correct\n";
    } else {
        cout << "too short\n";
    }
}