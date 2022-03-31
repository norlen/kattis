#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Edge {
    int v;
    ll w;
    ll t;
    ll p;

    Edge(int v, ll w, ll t, ll p): v(v), w(w), t(t), p(p) {}
};

int main() {
    bool first = true;
    while (true) {
        int n, m, q, s;
        cin >> n >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0) break;
        if (!first) cout << endl;
        first = false;

        vector<vector<Edge>> edges(n);
        for (int i = 0; i < m; ++i) {
            int u, v, t, p, w;
            cin >> u >> v >> t >> p >> w;
            edges[u].push_back(Edge(v, w, t, p));
        }

        vector<ll> d(n, numeric_limits<ll>::max());
        d[s] = 0;

        using T = pair<ll,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, s});
        
        while (!pq.empty()) {
            ll t = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (auto edge : edges[u]) {
                ll wait = 0;
                if (t <= edge.t) {
                    wait = t + edge.t - t;
                } else {
                    if (edge.p == 0) continue;
                    ll P = (t - edge.t + edge.p) / edge.p;
                    wait = edge.t + edge.p * P;
                }
                ll dist = wait + edge.w;
                if (dist < d[edge.v]) {
                    d[edge.v] = dist;
                    pq.push({d[edge.v], edge.v});
                }
            }
        }

        for (int i = 0; i < q; ++i) {
            int v;
            cin >> v;

            if (d[v] == numeric_limits<ll>::max()) {
                cout << "Impossible\n";
            } else {
                cout << d[v] << endl;
            }
        }
    }
}