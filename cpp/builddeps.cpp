#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    string in, start;
    getline(cin, in);

    unordered_set<string> nodes;
    unordered_map<string, vector<string>> edges;
    unordered_map<string, int> indegree;

    for (int i = 0; i < n; ++i) {
        getline(cin, in);
        string u = in.substr(0, in.find(':'));
        string rest = in.substr(in.find(':')+1);
        stringstream ss;
        ss << rest;
        nodes.insert(u);

        string v;
        while (ss >> v) {
            edges[v].push_back(u);
            indegree[u]++;
        }
    }
    getline(cin, start);
    
    stack<string> s;
    for (auto n : nodes) {
        if (indegree[n] == 0) {
            s.push(n);
        }
    }

    vector<string> top_sort;
    while (!s.empty()) {
        auto u = s.top();
        s.pop();

        top_sort.push_back(u);
        for (auto v : edges[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                s.push(v);
            }
        }
    }

    vector<string> ans;
    
    unordered_set<string> in_path;
    unordered_map<string, bool> visited;
    deque<string> q;
    q.push_back(start);
    visited[start] = true;

    while (!q.empty()) {
        auto u = q.front();
        q.pop_front();
        in_path.insert(u);

        for (auto v : edges[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            q.push_back(v);
        }
    }

    for (auto n : top_sort) {
        if (in_path.count(n)) {
            cout << n << endl;
        }
    }
}
