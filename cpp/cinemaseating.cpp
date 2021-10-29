#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, c, n;
    cin >> r >> c >> n;

    vector<vector<bool>> g(r, vector<bool>(c, 0));
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a-1][b-1] = true;
    }

    vector<int> k(9, 0);
    vector<pair<int,int>> offsets = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (g[i][j] == false) continue;
            int count = 0;
            for (auto o : offsets) {
                int u = i + o.first;
                int v = j + o.second;
                if (u < 0 || u >= r || v < 0 || v >= c || g[u][v] == false) continue;
                count++;
            }
            k[count]++;
        }
    }
    
    for (int i = 0; i < k.size(); ++i) {
        cout << k[i] << (i == k.size()-1 ? "\n" : " ");
    }
}