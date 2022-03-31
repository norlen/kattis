#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<int,int> get_offset(char ch) {
    if (ch == 'N') {
        return {-1,0};
    }
    if (ch == 'S') {
        return {1,0};
    }
    if (ch == 'E') {
        return {0,1};
    }
    return {0,-1};
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    set<pair<int,int>> visited;
    pair<int,int> s = {0, 0};

    int moves = 0;
    while (true) {
        if (grid[s.first][s.second] == 'T') {
            cout << moves << endl;
            break;
        }

        if (visited.count(s) > 0) {
            cout << "Lost\n";
            break;
        }
        visited.insert(s);

        pair<int,int> offset = get_offset(grid[s.first][s.second]);
        int vr = s.first + offset.first;
        int vc = s.second + offset.second;

        if (vr < 0 || vr >= n || vc < 0 || vc >= m) {
            cout << "Out\n";
            break;
        }

        s = {vr, vc};
        moves++;
    }
}
