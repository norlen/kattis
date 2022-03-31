#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class UnionFind {
public:
    UnionFind(ll size): root(size), rank(size) {
        for (ll i = 0; i < size; ++i) {
            root[i] = i;
            rank[i] = i;
        }
    }
    
    ll find(ll x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    
    void unionSet(ll x, ll y) {
        ll rootX = find(x);
        ll rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
    
    bool connected(ll x, ll y) {
        return find(x) == find(y);
    }

    vector<ll> root;
    vector<ll> rank;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, u, v;

    cin >> n;
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
    }

    UnionFind un(n);

    cin >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        un.unionSet(u-1, v-1);
    }

    map<ll,ll> mm;
    for (ll i = 0; i < n; ++i) {
        mm[un.root[i]] += p[i];
    }

    ll lowest = numeric_limits<ll>::max();
    ll best_node = 0;
    for (ll i = 0; i < n; ++i) {
        ll v = mm[un.root[i]];
        if (v < lowest) {
            lowest = v;
            best_node = i + 1;
        }
    }

    cout << best_node << endl;
}
