#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class UnionFind {
public:
    UnionFind(int size): root(size), rank(size) {
        for (int i = 0; i < size; ++i) {
            root[i] = i;
            rank[i] = i;
        }
    }
    
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
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
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UnionFind un(n);
    string output;
    for (int i = 0; i < q; ++i) {
        char op;
        int a, b;
        cin >> op >> a >> b;

        if (op == '?') {
            if (un.connected(a, b)) {
                output += "yes\n";
            } else {
                output += "no\n";
            }
        } else {
            un.unionSet(a, b);
        }
    }

    cout << output;
}