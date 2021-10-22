#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        p[u-1]++;
        p[v-1]++;
    }

    for (int i = 0; i < n; ++i) {
        cout << (p[i] - (i+1)) << endl;
    }
}
