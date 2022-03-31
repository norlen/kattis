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
    int n, m;
    cin >> n >> m;

    UnionFind un(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        un.unionSet(u-1, v-1);
    }

    bool connected = true;
    for (int i = 1; i < n; ++i) {
        if (!un.connected(0, i)) {
            cout << (i+1) << endl;
            connected = false;
        }
    }

    if (connected) {
        cout << "Connected\n";
    }
}
