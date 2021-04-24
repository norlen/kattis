#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == -1) break;

        int adjmat[21][21] = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch;
                cin >> ch;
                adjmat[i][j] = ch - '0';
            }
        }

        vector<int> weaks;
        for (int u = 0; u < n; ++u) {
            bool weak = true;
            for (int v = 0; (v < n) && weak; ++v) {
                if (adjmat[u][v] > 0) {
                    for (int w = 0; (w < n) && weak; ++w) {
                        if (adjmat[v][w] > 0 && adjmat[u][w] > 0) {
                            weak = false;
                        }
                    }
                }
            }
            if (weak) weaks.push_back(u);
        }

        for (int i = 0; i < weaks.size(); ++i) {
            cout << weaks[i] << (i == weaks.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}