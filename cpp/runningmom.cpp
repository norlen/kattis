#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool in_stack(vector<int>& stack, int u) {
    for (auto s : stack) {
        if (s == u) {
            return true;
        }
    }
    return false;
}

void dfs(int u, vector<vector<int>>& edges, vector<int>& stack, vector<bool>& can_reach_cycle, vector<bool>& vis) {
    vis[u] = true;

    stack.push_back(u);
    for (int v : edges[u]) {
        if (vis[v]) {
            // Basic DFS, but if we have seen this node before and
            // 1. It's a back edge (in our stack), we have a cycle. Since every node in our stack
            //    can reach the cycle, all nodes in the stack are safe.
            // 2. The node we're visiting is safe then it has a cycle somewhere, i.e., this one and
            //    all that can reach this one are also safe.
            if ((in_stack(stack, v) || can_reach_cycle[v])) {
                for (auto s : stack) {
                    can_reach_cycle[s] = true;
                }
            }
        } else {
            dfs(v, edges, stack, can_reach_cycle, vis);
        }
    }
    stack.pop_back();
}

int get_idx(const string& s, unordered_map<string, int>& mp, int& c) {
    if (mp.count(s) == 0) {
        mp[s] = c;
        return c++;
    }
    return mp[s];
}

int main() {
    // To determine if a city is safe the only criteria is essentially if a node allows us to
    // enter a cycle.
    //
    // If we can enter a cycle from a node, the node is safe. Otherwise, it is not. From the
    // description a node cannot have an edge to itself so that case isn't worth considering.
    int n;
    cin >> n;

    int count = 0;
    unordered_map<string, int> city_to_id;

    vector<vector<int>> edges = vector(n, vector<int>());
    string src, dst;
    for (int i = 0; i < n; ++i) {
        cin >> src >> dst;
        int si = get_idx(src, city_to_id, count);
        int di = get_idx(dst, city_to_id, count);
        edges[si].push_back(di);
    }

    vector<int> stack;
    vector<bool> can_reach_cycle(n, false);
    vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i) {
        dfs(i, edges, stack, can_reach_cycle, vis);
    }

    string check;
    while (cin >> check) {
        cout << check << (can_reach_cycle[city_to_id[check]] ? " safe" : " trapped") << endl;
    }
}
