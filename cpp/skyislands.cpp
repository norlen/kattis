#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class union_find {
public:
    union_find(int size): root(size), rank(size) {
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
    
    void union_set(int x, int y) {
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

    union_find islands(n);

    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        islands.union_set(u-1, v-1);
    }

    bool valid = true;
    for (int i = 1; i < n; ++i) {
        if (!islands.connected(0, i)) {
            valid = false;
            break;
        }
    }

    cout << (valid ? "YES\n": "NO\n");
}
