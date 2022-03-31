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

using T = pair<int,pair<int,int>>;

int main() {
    int n;
    cin >> n;

    UnionFind un(n);
    priority_queue<T, vector<T>, greater<T>> pq;

    vector<vector<int>> e(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> e[i][j];
            pq.push({e[i][j], {i, j}});
        }
    }

    vector<pair<int,int>> final_edges;
    while (!pq.empty() || !final_edges.size() == n-1) {
        auto u = pq.top().second.first;
        auto v = pq.top().second.second;
        pq.pop();

        if (un.connected(u, v)) continue;
        un.unionSet(u, v);
        final_edges.push_back({min(u, v), max(u, v)});
    }

    sort(final_edges.begin(), final_edges.end());
    for (auto e : final_edges) {
        cout << e.first+1 << " " << e.second+1 << endl;
    }
}
