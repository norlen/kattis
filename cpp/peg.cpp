#include <iostream>
#include <vector>

using namespace std;

int main() {
    string in;
    vector<string> g;
    while (getline(cin, in)) {
        g.push_back(in);
    }

    int moves = 0;
    int n = g.size(), m = g[0].size();
    pair<int,int> offsets[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] != '.') continue;
            for (pair<int,int> o : offsets) {
                pair<int,int> p2 = { i + 2*o.first, j + 2*o.second };
                if (p2.first < 0 || p2.first >= n || p2.second < 0 || p2.second >= m) continue;
                if (g[p2.first][p2.second] != 'o') continue;
                pair<int,int> p1 = { i + o.first, j + o.second };
                if (g[p1.first][p1.second] != 'o') continue;
                moves++;
            }
        }
    }

    cout << moves << endl;
}