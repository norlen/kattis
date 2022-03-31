#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int mh_dist(pair<int,int> lhs, pair<int,int> rhs) {
    int dx = abs(rhs.first - lhs.first);
    int dy = abs(rhs.second - lhs.second);
    return (dx+dy);
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;

        vector<pair<int,int>> locs(n+2);
        for (int i = 0; i < n+2; ++i) {
            cin >> locs[i].first >> locs[i].second;
        }

        // pair<int,int> home;
        // cin >> home.first >> home.second;

        // vector<pair<int,int>> stores(n);
        // for (int i = 0; i < n; ++i) {
        //     cin >> stores[i].first >> stores[i].second;
        // }

        // pair<int,int> end;
        // cin >> end.first >> end.second;

        int start = 0;
        int end = n+1;

        int max_dist = 20 * 50;

        vector<bool> visited(n+2, false);
        stack<int> s;
        s.push(start);
        visited[start] = true;

        bool happy = false;
        while (!s.empty()) {
            auto u = s.top();
            s.pop();

            if (u == end) {
                happy = true;
            }

            pair<int,int> l1 = locs[u];
            for (int i = 0; i < n+2; ++i) {
                if (visited[i]) continue;
                pair<int,int> l2 = locs[i];
                int dist = mh_dist(l1, l2);
                // cout << "l1.x=" << l1.first << ", l1.y=" << l1.second << ", l2.x=" << l2.first << ", l2.y=" << l2.second << endl;
                // cout << "u=" << u << ", v=" << i << ", dist=" << dist << endl;
                if (dist <= max_dist) {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }

        if (happy) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }




    }
}