#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int find_p(vector<int>& parents, int u) {
    if (u != parents[u]) {
        parents[u] = find_p(parents, parents[u]);
    }
    return parents[u];
}

double kruskals(int num_nodes, int source, vector<pair<double, pair<int,int>>>& edges) {
    double len = 0.0;
    vector<int> p(num_nodes);
    for (int i = 0; i < num_nodes; ++i) {
        p[i] = i;
    }

    sort(edges.begin(), edges.end());

    for (pair<double,pair<int,int>> edge : edges) {
        int r1 = find_p(p, edge.second.first);
        int r2 = find_p(p, edge.second.second);
        if (r1 != r2) {
            len += edge.first;
            p[r2] = r1;
        }
    }
    return len;
}

int main() {
    cout << setprecision(10);

    int cases;
    cin >> cases;
    for (int t = 0; t < cases; ++t) {
        int islands;
        cin >> islands;

        vector<pair<double, double>> ps(islands);
        for (int i = 0; i < islands; ++i) {
            cin >> ps[i].first >> ps[i].second;
        }

        vector<pair<double, pair<int,int>>> edges;
        for (int i = 0; i < islands; ++i) {
            for (int j = i+1; j < islands; ++j) {
                auto d = sqrt(powf64(ps[i].first-ps[j].first, 2.0) + powf64(ps[i].second-ps[j].second, 2.0));
                edges.push_back({d, {i, j}});
                edges.push_back({d, {j, i}});
            }
        }
        auto len = kruskals(islands, 0, edges);
        cout << len << endl;
    }
}