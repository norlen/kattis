#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool is_prime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

vector<string> get_variations(int n) {
    vector<string> ans;
    string N = to_string(n);
    for (int i = 0; i < 4; ++i) {
        int l = N[i];
        N[i] = '*';
        ans.push_back(N);
        N[i] = l;
    }
    return ans;
}

int find_path(unordered_map<string, vector<int>>& nodes, int s, int t) {
    deque<pair<int,int>> q;
    unordered_set<int> visited;
    q.push_back({s, 0});
    visited.insert(s);

    while (!q.empty()) {
        auto u = q.front().first;
        auto cost = q.front().second;
        q.pop_front();

        if (u == t) {
            return cost;
        }

        auto variations = get_variations(u);
        for (auto variant : variations) {
            for (auto v : nodes[variant]) {
                // cout << "Possible path=" << variant << ", prime=" << v << endl;
                if (visited.count(v) > 0) continue;
                visited.insert(v);
                q.push_back({v, cost+1});
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;

    vector<int> primes;
    for (int i = 1000; i < 10000; ++i) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }
    unordered_map<string, vector<int>> nodes;
    for (auto prime : primes) {
        auto variations = get_variations(prime);
        for (auto v : variations) {
            nodes[v].push_back(prime);
        }
    }

    for (int U = 0; U < T; ++U) {
        int s, t;
        cin >> s >> t;

        auto cost = find_path(nodes, s, t);
        if (cost == -1) {
            cout << "Impossible\n";
        } else {
            cout << cost << endl;
        }
    }
}
