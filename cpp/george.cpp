#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    int a, b, k, g;
    cin >> a >> b >> k >> g;
    // a: start node
    // b: end node
    // k: wait time until start
    // g; num edges george
    // cout << "start=" << a << ", end=" << b << endl;

    vector<int> g_path(g);
    for (int i = 0; i < g; ++i) cin >> g_path[i];


    map<pair<int,int>, int> edges2;
    vector<vector<pair<int,int>>> edges(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, l;
        cin >> u >> v >> l;

        edges[u].push_back({v, l});
        edges[v].push_back({u, l});
        edges2.insert({{u, v}, l});
        edges2.insert({{v, u}, l});
    }

    int curr_time = 0;
    map<pair<int,int>, pair<int,int>> wait_times;
    for (int i = 1; i < g_path.size(); ++i) {
        int u = g_path[i-1];
        int v = g_path[i];
        int cost = edges2[{u, v}];
        int end_time = curr_time + cost;

        // cout << "u=" << u << " -> v=" << v << ", start=" << curr_time << " end=" << end_time << endl;
        // wait_times[{min(u, v), max(u, v)}] = {curr_time, end_time};
        wait_times[{u, v}] = {curr_time, end_time};
        wait_times[{v, u}] = {curr_time, end_time};
        curr_time = end_time;
    }
    // cout << endl;

    vector<int> dist(n+1, INT32_MAX);
    using T = pair<int,int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({k, a});
    dist[a] = k;

    while (!pq.empty()) {
        int curr_time = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        // cout << "u=" << u << ", time=" << curr_time << endl;

        if (u == b) {
            // cout << "OK\n";
            cout << curr_time - k << endl;
            break;
        }

        for (pair<int,int> edge : edges[u]) {
            int v = edge.first;
            int w = edge.second;
            int d;
            pair<int,int> k = {min(u, v), max(u, v)};
            // cout << " time=" << curr_time << ", wait_start=" << wait_times[k].first << ", end=" << wait_times[k].second << endl;
            // cout << "  v=" << v << ", w=" << w << ", ";
            int wait_start = wait_times[k].first;
            int wait_end = wait_times[k].second;
            if (wait_start <= curr_time && curr_time < wait_end) {
                d = wait_times[k].second + w;
                // cout << "d=" << wait_times[k].second << "+" << w << "=" << d << " WAITING\n";
            } else {
                d = curr_time + w;
                // cout << "d=" << d << endl;
            }

            if (d < dist[v]) {
                // cout << "  --relax\n";
                dist[v] = d;
                pq.push({d, v});
            }
        }
    }
}
